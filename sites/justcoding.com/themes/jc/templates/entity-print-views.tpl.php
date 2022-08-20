<?php

/**
 * @file
 * PDF template for printing.
 *
 * Available variables are:
 *  - $view - The view itself.
 *  - $view_html - The rendered $view html.
 */
?>

<html>
<head>
  <meta charset="utf-8">
  <title>PDF</title>
  <?php
    //print drupal_get_css($entity_print_css);
  ?>
  <style type="text/css" media="screen,print">
       /* Page Breaks */

    .node--article {
     margin-bottom: 75px;
    }

    .views-row-last {
      margin-bottom: 50px;
    }
    /***Always insert a page break before the element***/
    p {
      font-family: "Open Sans",sans-serif;
      font-size: 14px;
    }
    a {
    color: #145F7B;
    }
   </style>

</head>
<body>
<div class="page">
  <?php
    global $base_url;
    $view_html2 = $view_html;
    $view_html2 = str_replace('href="/articles/', 'href="' . $base_url . '/articles/',$view_html2);
    $view_html2 = str_replace('href="/article-categories/', 'href="' . $base_url . '/article-categories/', $view_html2);
  ?>

  <?php  print $view_html2; ?>
  <br>
  <p><i>"Except where specifically encouraged, no part of this publication may be reproduced, in any form or by any means, without prior written consent of HCPro, or the Copyright Clearance Center at 978-750-8400. Opinions expressed are not necessarily those of JustCoding. Mention of products and services does not constitute endorsement. Advice given is general, and readers should consult professional counsel for specific legal, ethical, or clinical questions"</i></p>
</div>
</body>
</html>
