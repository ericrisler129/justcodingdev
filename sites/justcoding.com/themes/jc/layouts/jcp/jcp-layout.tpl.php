<?php $theme_path = hcprobt_get_path(); ?>
<div<?php print $attributes; ?>>

  <div class="l-top">
    <div class="l-site-width">
      <?php print render($page['top']); ?>
    </div>
  </div>

  <header class="l-header" role="banner">
    <div class="l-site-width">
      <div class="l-branding">

        <?php if (user_is_logged_in()): ?>
          <div class="welcome-message">
            Welcome, <a id="uname-gtm" href="/edit-profile"><?php print ucfirst($GLOBALS['user']->name); ?></a>.
            Account Level:
            <?php
            foreach($GLOBALS['user']->roles as $role) {
              if ($role != 'authenticated user') {
                print "<a id='utype-gtm' href='/edit-profile'>" . ucwords($role) . "</a>&nbsp;";
              }
            }
            if (!user_has_role_name("platinum" || "PROPEL Coding")) {
              print "<a href='/edit-profile'>(Upgrade!)</a>";
            }
            ?>
          </div>
        <?php endif; ?>

        <table><tr>
		<?php if ($logo): ?>
          <td><a href="<?php print $front_page; ?>" title="<?php print t('Home'); ?>" rel="home" class="site-logo"><img src="<?php print $logo; ?>" alt="<?php print t('Home'); ?>" /></a></td>
		<?php endif; ?>
		  <?php $propel_header = "/sites/justcoding.com/files/propel.png?v= .time();"; global $base_url; $propel = $base_url . '/propel';?>
		  <?php $get_roles = $GLOBALS['user']->roles; foreach($get_roles as $get_role): ?> <td><?php if ($get_role == "PROPEL Coding"): ?><a href="<?php print $propel; ?>" title="<?php print t('PROPEL Home'); ?>" class="propel-header"><img src="<?php print $propel_header; ?>" /></a></td> <?php endif; endforeach; ?>
		</tr></table>
      </div>
      <?php print render($page['header']); ?>
    </div>
  </header>

  <div class="l-navigation">
    <div class="l-site-width">
      <?php print render($page['navigation']); ?>
    </div>
  </div>

  <div class="l-section-header">
    <?php if (isset($section_title)): ?>
      <span class="section-icon"><span class="section-icon-inner"></span></span>
      <span class="section-title"><?php print $section_title; ?></span>
	  <span class="section-breadcrumbs"><?php print $breadcrumb; ?></span>
    <?php endif; ?>
    <?php if (isset($section_subtitle)): ?>
      <span class="section-subtitle"><?php print $section_subtitle; ?></span>
    <?php endif; ?>
  </div>

  <div class="l-main">
    <div class="l-masthead">
      <?php print render($page['masthead']); ?>
    </div>

    <?php print $messages; ?>
    <?php print render($tabs); ?>
    <?php if ($action_links): ?>
      <ul class="action-links"><?php print render($action_links); ?></ul>
    <?php endif; ?>

    <div class="l-content" role="main">
      <a id="main-content"></a>

      <?php print render($title_prefix); ?>
      <?php if ($title): ?>
        <div class="main-title-wrapper">
          <h1 class="main-h1"><?php print $title; ?></h1>
        </div>
      <?php endif; ?>
      <?php print render($title_suffix); ?>

      <?php print render($page['content']); ?>
    </div>

    <?php print render($page['sidebar_first']); ?>
    <?php print render($page['sidebar_second']); ?>
    <aside class="l-content-bottom">
      <?php print render($page['content_bottom']); ?>
    </aside>
  </div>

  <footer class="l-footer" role="contentinfo">
    <div class="l-site-width">
      <div class="hcpro-logo"><img src="/<?php print $theme_path; ?>/images/footer-logo.png" /></div>
      <?php print render($page['footer']); ?>
      <?php if (theme_get_setting('hcpro_copyright')): ?>
        <div class="copyright"><?php print theme_get_setting('hcpro_copyright'); ?></div>
      <?php endif; ?>
    </div>
  </footer>

  <div class="l-bottom">
    <div class="l-site-width">
      <?php print render($page['bottom']); ?>
    </div>
  </div>

</div>
