<?php if(!empty($profile)): ?>
  <form method="post" id="password-form">
    <div class="column column-left">
      <div class="profile-section block standard-block">
        <div class="title-wrapper">
          <h2 class="block__title">Site Details</h2>
        </div>
        <div class="block__content">
          <div class="form-item form-item-half">
            <label>Subscription Level</label>
            <input type="text" value="<?php echo htmlspecialchars($profile['membership tier']); ?>" disabled />
          </div>
          <?php if(isset($profile['memberships'][0]['expiration_date'])): ?>
            <div class="form-item form-item-half">
              <label>Expiration</label>
              <input type="text" value="<?php echo $profile['memberships'][0]['expiration_date']; ?>" disabled />
            </div>
          <?php endif; ?>

          <?php if(isset($profile['membership tier']) && !empty($profile['membership tier']) && strpos($profile['membership tier'], "Platinum") === FALSE): ?>
            <div class="clearfix"></div>
            <div class="form-item">
              <label>&nbsp;</label>
              <div class="profile-upgrade-number">To Upgrade Call:<br />1-800-650-6787</div>
              <!--div class="button">
                <a class="button-grey" href="http://store.blr.com/" target="_blank">Upgrade Membership!</a>
              </div-->
            </div>
            <div class="profile-details">
              <p class="heading">Why Upgrade?</p>
              <p>Upgrade your subscription to JustCoding to have access to weekly articles and quizzes with AAPC, AHIMA, and CCDS credits. You can also get access to our tools and resources library, Clinical Conditions Encyclopedia, monthly newsletters BAPCs and BCCS, and much more!</p>
              <p><a href="/membership/join">Click here</a> to learn more about your subscription options for JustCoding.</p>
            </div>

          <?php endif; ?>
          <div class="clearfix"></div>
          <?php if(empty($profile['membership tier']) || $profile['is_expired']): ?>
            <div class="form-item clearfix">
              <label>&nbsp;</label>
              <div class="profile-upgrade-number">To Renew Call:<br />1-800-650-6787</div>
            </div>
            <div class="profile-details">
              <p>Renew your subscription to JustCoding to have access to weekly articles and quizzes with AAPC, AHIMA, and CCDS credits. You can also get access to our tools and resources library, Clinical Conditions Encyclopedia, monthly newsletters BAPCs and BCCS, and much more!
              <p><a href="/membership/join">Click here</a> to learn more about your subscription options for JustCoding.</p>
            </div>

          <?php endif; ?>
          <div class="clearfix"></div>
        </div>
      </div>

      <div class="profile-section block standard-block">
        <div class="title-wrapper">
          <h2 class="block__title">Global Username</h2>
        </div>
        <div class="block__content">
          <div class="form-item">
            <label>Username</label>
            <input type="text" value="<?php echo htmlspecialchars($profile['username']); ?>" disabled />
          </div>
          <!--div class="form-item form-item-half">
            <label>New Password</label>
            <input type="password" name="password" disabled />
          </div>
          <div class="form-item form-item-half">
            <label>Confirm Password</label>
            <input type="password" name="password2" disabled />
          </div-->
          <div class="form-item">
            <label>Current E-mail</label>
            <input type="email" name="email" value="<?php echo htmlspecialchars($profile['email']); ?>" disabled />
          </div>
          <div class="profile-details">
            <p>A valid e-mail address. All e-mails from the system will be sent to this address. The e-mail address is not made public and will only be used if you wish to receive a new password or wish to receive certain news or notifications by e-mail.</p>
          </div>
		  <div class="reset-password">
		    <a href="/user/password">Change your password</a>
		  </div>
        </div>
      </div>
    </div>

    <div class="column column-right">
      <div class="profile-section block standard-block">
        <div class="title-wrapper">
          <h2 class="block__title">Your Global Profile</h2>
        </div>
        <div class="block__content">
          <div class="column-left">
            <div class="profile-image">
              <label>Picture</label>
              <?php if(isset($profile['profile_image'])): ?>
                <img src="<?php echo $profile['profile_image']; ?>" />
              <?php else: ?>
                <img src="http://front.webauth.blrstage.com/images/profile-image-placeholder.png" />
              <?php endif; ?>
            </div>
            <div class="form-item">
              <label>Your Member ID</label>
              <input type="text" value="<?php echo $profile['memberships'][0]['customer_id']; ?>" disabled />
              <p class="help-text profile-details">Please provide this ID when calling customer service</p>
            </div>
          </div>
          <div class="column-right">
            <div class="form-item">
              <label>First Name</label>
              <input type="text" value="<?php echo $profile['profile_address']['first_name']; ?>" disabled />
            </div>
            <div class="form-item">
              <label>Last Name</label>
              <input type="text" value="<?php echo $profile['profile_address']['last_name']; ?>" disabled />
            </div>
            <div class="form-item">
              <label>Title</label>
              <input type="text" value="<?php echo $profile['profile_address']['title']; ?>" disabled />
            </div>
            <div class="form-item">
              <label>Company</label>
              <input type="text" value="<?php echo $profile['profile_address']['company']; ?>" disabled />
            </div>
            <div class="form-item">
              <label>Phone Number</label>
              <input type="text" value="<?php echo $profile['profile_address']['phone_number']; ?>" disabled />
            </div>
            <div class="form-item">
              <label>Address Line 1</label>
              <input type="text" value="<?php echo $profile['profile_address']['street']; ?>" disabled />
            </div>
            <div class="form-item">
              <label>City</label>
              <input type="text" value="<?php echo $profile['profile_address']['city']; ?>" disabled />
            </div>
            <div class="form-item">
              <label>Region</label>
              <input type="text" value="<?php echo $profile['profile_address']['region']; ?>" disabled />
            </div>
            <div class="form-item">
              <label>Zip Code</label>
              <input type="text" value="<?php echo $profile['profile_address']['postal_code']; ?>" disabled />
            </div>
          </div>
        </div>
      </div>
    </div>

    <div class="profile-section profile-section-bottom">
      <p>Need Help? Contact Us at 1-800-650-6787</p>
      <!--div class="profile-submit">
        <div class="button">
          <button type="submit" class="button button-black" disabled>Change Password</button>
        </div>
      </div-->
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
