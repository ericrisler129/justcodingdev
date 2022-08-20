<?php
error_reporting(error_reporting() & ~E_NOTICE);
libxml_use_internal_errors(true);

function display_xml_error($error, $xml)
{
    $return  = $xml[$error->line - 1] . "\n";
    $return .= str_repeat('-', $error->column) . "^\n";
    switch ($error->level) {
        case LIBXML_ERR_WARNING: $return .= "Warning $error->code: "; break;
        case LIBXML_ERR_ERROR: $return .= "Error $error->code: "; break;
        case LIBXML_ERR_FATAL: $return .= "Fatal Error $error->code: "; break;
    }
    $return .= trim($error->message) . "\n  Line: $error->line" . "\n  Column: $error->column";
    if ($error->file) 
        $return .= "\n  File: $error->file";
    return "$return\n\n--------------------------------------------\n\n";
}

function utf8_for_xml($string)
{
    return preg_replace ('/[^\x{0009}\x{000a}\x{000d}\x{0020}-\x{D7FF}\x{E000}-\x{FFFD}]+/u', ' ', $string);
}

function legacy_html_entity_decode($str, $quotes = ENT_QUOTES, $charset = 'UTF-8') {
    $out = html_entity_decode(preg_replace_callback('/&#(\d+);/', function ($m) use ($quotes, $charset) {
        if (0x80 <= $m[1] && $m[1] <= 0x9F) {
            return iconv('cp1252', $charset, html_entity_decode($m[0], $quotes, 'cp1252'));
        }
        return html_entity_decode($m[0], $quotes, $charset);
    }, $str));
    $out = str_replace('&rsquo;',html_entity_decode("&#x2019;", ENT_COMPAT, 'UTF-8'),$out);
    return $out;
}

function inner_html($node) {
    $innerHTML= ''; 
    $children = $node->childNodes; 
    foreach ($children as $child) { 
        $innerHTML .= $child->ownerDocument->saveXML( $child ); 
    } 

    return $innerHTML; 
}

function attribute_text($element,$attr) {
  $nodes = $element->getElementsByTagName($attr);
  $out = '';
  for($i = 0; $i < $nodes->length; $i++)
    $out .= inner_html($nodes->item($i));
  return $out;
 }

function attribute_text_field($element,$attr) {
  $nodes = $element->getElementsByTagName('field');
  $out = '';
  for($i = 0; $i < $nodes->length; $i++)
    if($nodes->item($i)->getAttribute('name') == $attr)
       $out .= inner_html($nodes->item($i));
  return $out;
 }

function az($s) {
  return strtolower(preg_replace("/[^a-zA-Z0-9]+/", "", $s));
}

// Create taxonomy lookup arrays
$vid = taxonomy_vocabulary_machine_name_load('volume_and_issue')->vid;
$parents = [];
foreach(taxonomy_get_tree($vid,0) as $term) {
 $parents[$term->tid] = $term;
 $name = $term->name;
 foreach($term->parents as $parent_tid) {
   if(!$parent_tid || !isset($parents[$parent_tid])) continue;
   $name = $parents[$parent_tid]->name . '/' . $name;
 }
 $tax['volume_and_issue'][$name] = $term->tid;
}
  
$in = array();
$x = 0;
echo "Preparing content";

$fields = explode(',','legacy_content_id,volume,issue');

echo "Loading XML document jcp.xml";
 
$xml = new DOMDocument(); 

$str = utf8_for_xml(file_get_contents('legacy/jcp.xml'));
$xml->loadXML($str,LIBXML_HTML_NOIMPLIED);
$xmlstr = explode("\n",$str);

$errors = libxml_get_errors();
if(!empty($errors)) {
  foreach ($errors as $error)
     echo display_xml_error($error, $xmlstr);
  die();
}

$xpath = new DOMXpath($xml);

$volumes = array(false,false);

foreach($xml->getElementsByTagName('content') as $content) {
  if((++$x) % 10 == 0) { echo "."; }
  $info = array();
  foreach($fields as $field)
    $info[$field] = attribute_text($content,$field);
  $in[$info['legacy_content_id']] = $info;  
}
echo "\n";


function summary_cmp($text) {
  $text = legacy_html_entity_decode($text);	
  $text = strtolower(strip_tags($text));
  $text = preg_replace("/[^A-Za-z0-9 ]/", '', $text);
  return trim($text);
}

$contentMap = array();

echo "Loading existing content.\n";
$query = db_query("select * from field_revision_field_legacy_content_id");
while($row = $query->fetchAssoc())
  $contentMap[$row['field_legacy_content_id_value']] = $row['entity_id'];

$toDelete = array();
	    
    $nodes = array();

    // First pass: create new entities and load existing ones
    $toLoad = array();
    foreach($in as $data) {
      $content_id = $data['legacy_content_id'];
      if(isset($contentMap[$content_id]))
        $toLoad[] = $contentMap[$content_id];
      else
        die($content_id);
    }

    foreach(node_load_multiple($toLoad) as $node) {
      $w = entity_metadata_wrapper('node',$node);
      $nodes[$w->field_legacy_content_id->value()] = $node;
    }

   // Second pass: update entity data
   foreach($in as $data) {
      $content_id = $data['legacy_content_id']; 
      if(!isset($nodes[$content_id])) 
       die('no node for '.$content_id);
      $node = $nodes[$content_id];
try {
      $w = entity_metadata_wrapper('node',$node);

      if(!empty($data['volume']) && !empty($data['issue']) && isset($w->field_volume_and_issue)) {
         $value = $data['volume'] . '/' . $data['issue'];

	 if(isset($tax['volume_and_issue'][$value]) && $w->field_volume_and_issue != $tax['volume_and_issue'][$value]) {
   	   $w->field_volume_and_issue = $tax['volume_and_issue'][$value];	   
	   $w->save();
	   echo '+';
	   continue;
         }
      }

      echo '.';

} catch( Exception $e ) {
var_dump($data);
var_dump($e);
echo $e->getMessage();
die();
}
   }
