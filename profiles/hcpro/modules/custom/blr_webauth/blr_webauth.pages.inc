<?php

function blr_webauth_user_profile_page() {
  global $user;
  drupal_set_title("Your Account Information");
  $profile = blr_webauth_get_profile();

  $profile['membership tier'] = $user->roles;
  unset($profile['membership tier'][2]);
  $profile['membership tier'] = ucwords(implode(', ', $profile['membership tier']));

  $profile['is_expired'] = FALSE;
  if (isset($profile['memberships'][0]['expiration_date'])) {
    $date = strtotime($profile['memberships'][0]['expiration_date']);
    if ($date < time()) {
      $profile['is_expired'] = TRUE;
    }
  }
  return theme('mbprofile',['profile'=>$profile]);
}

