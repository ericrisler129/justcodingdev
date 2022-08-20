<?php if(!empty($subscription) && !empty($user)): ?>

<form method="post" id="password-form">
  <div class="column column-left">
    <div class="profile-section">
      <div class="form-item form-item-half">
        <label>Subscription Level</label>
        <input type="text" value="<?php echo htmlspecialchars($subscription['Membership Tier']); ?>" disabled />
      </div>
      <div class="profile-details">
        <p class="heading">Why Upgrade?</p>
        <ul>
          <li>Lorem ipsum dolor sit amet</li>
          <li>Lorem ipsum dolor sit amet</li>
          <li>Lorem ipsum dolor sit amet</li>
        </ul>
      </div>
    </div>

    <div class="profile-section">
      <div class="form-item form-item-half">
        <label>New Password</label>
        <input type="password" name="password" />
      </div>
      <div class="form-item form-item-half">
        <label>Confirm Password</label>
        <input type="password" name="password2" />
      </div>
      <div class="form-item">
        <label>Current E-mail</label>
        <input type="email" name="email" value="<?php echo htmlspecialchars($user['Email']); ?>" disabled />
      </div>
      <div class="profile-details">
        <p>A valid e-mail address. All e-mails from the system will be sent to this address. The e-mail address is not made public and will only be used if you wish to receive a new password or wish to receive certain news or notifications by e-mail.</p>
      </div>
    </div>
  </div>

  <div class="column column-right">
    <div class="profile-section">
      <div class="form-item">
        <label>Your Member ID</label>
        <input type="text" value="<?php echo $user['UserId']; ?>" disabled />
        <p class="help-text">Please provide this ID when calling customer service</p>
      </div>
    </div>
  </div>

  <div class="profile-section profile-section-bottom">
    <p>Need Help? Contact Us at 1-800-999-9999</p>
    <div class="profile-submit">
      <div class="button">
        <button type="submit" class="button button-black">Change Password</button>
      </div>
    </div>
  </div>
</form>
<?php endif; ?>

<script>
  jQuery('#password-form').submit(function() {
    var p1 = jQuery('input[name=password]',this).val();
    var p2 = jQuery('input[name=password2]',this).val();
    if(p1.length < 5 || p2.length < 5) {
      alert('Please complete required fields.  Passwords must be at least 5 characters.');
      return false;
    }
    if(p1 != p2) {
      alert('Passwords do not match.');
      return false;
    }
    return true;
  });
</script>
