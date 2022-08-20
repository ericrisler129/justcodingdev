<?php

/**
 * @file
 * PDF template for printing.
 *
 * Available variables are:
 *  - $entity - The entity itself.
 *  - $entity_array - The renderable array of this entity.
 *  - $entity_print_css - An array of stylesheets to be rendered.
 */
 Global $base_url;

?>

<html>
<head>
  <base href="<?php print $base_url ?>/">
  <meta charset="UTF-8">
  <title>PDF</title>
  <style>
    a {
      color: #145F7B;
    }
    body {
      font-family: "Open Sans", sans-serif;
    }
 </style>

</head>
<body>
<!--
<div id="header">
   <div style=""><p style="text-align: right;"><?php print date('n/j/y', $entity->created) ?> | Volume <?php print render($entity->field_publication[LANGUAGE_NONE][0]['volume']) ?> | Issue <?php print render($entity->field_publication[LANGUAGE_NONE][0]['issue']) ?></p></div>
</div>
-->
<div class="page">

  <h1 style="text-align: center; color: #1F9AC7; font-size: 38px; margin-bottom: 0px;"><?php print $entity->field_publication[LANGUAGE_NONE][0]['taxonomy_term']->name ?></h1>
  <h1 style="font-weight: bold; font-size: 25px; text-align: center; margin-top: 14px; margin-bottom: 40px;"><?php print render($entity->title) ?></h1>
   <?php if (isset($entity->field_pdf_editor_note[LANGUAGE_NONE][0]['value']) && $entity->field_pdf_editor_note[LANGUAGE_NONE][0]['value'] == 1) { ?>
     <p style="margin-bottom: 40px;"><i>Editor's note: The following is a CRC members only article that Credentialing Resource Center has made available to the public</i></p>
    <?php } ?>
  <?php print_r($entity->body[LANGUAGE_NONE][0]['safe_value']) ?>
  <br>
  <p><i>Except where specifically encouraged, no part of this publication may be reproduced, in any form or by any means, without prior written consent of HCPro, or the Copyright Clearance Center at 978-750-8400. Opinions expressed are not necessarily those of JustCoding. Mention of products and services does not constitute endorsement. Advice given is general, and readers should consult professional counsel for specific legal, ethical, or clinical questions.</i></p>
</div>
</body>
</html>
