<?php
if (isset($_GET['cookie'])) {
  setcookie('blr_username_remember', urldecode($_GET['cookie']));
}
