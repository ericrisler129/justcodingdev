;(function($) {

  Drupal.theme.prototype.equalizeheight = function (container) {

    var currentTallest = 0,
      currentRowStart = 0,
      rowDivs = [],
      $el,
      topPosition = 0;
    $(container).each(function() {
      $el = $(this);
      $($el).height('auto');
      topPostion = $el.position().top;
      if (currentRowStart != topPostion) {
        for (currentDiv = 0; currentDiv < rowDivs.length; currentDiv++) {
          rowDivs[currentDiv].height(currentTallest);
        }
        rowDivs.length = 0; // empty the array
        currentRowStart = topPostion;
        currentTallest = $el.height();
        rowDivs.push($el);
      } else {
        rowDivs.push($el);
        currentTallest = (currentTallest < $el.height()) ? ($el.height()) : (currentTallest);
      }
      for (currentDiv = 0; currentDiv < rowDivs.length; currentDiv++) {
        rowDivs[currentDiv].height(currentTallest);
      }
    });
  };

  Drupal.behaviors.accessLocks = {
    attach: function () {
      $('.front .view-articles, .view-quizzes').find('.views-row').once('access-lock', function () {
        if ($(this).find('.lock-icon').length) {
          $(this).addClass('access-locked');
        }
      });
    }
  };

  Drupal.behaviors.issueBrowser = {
    attach: function () {
      $('.year-link').click(function(e) {
        e.preventDefault();
        $(this).parent().find('.collapsible').toggleClass('collapsed');
      });

      $('.year-link').parent().find('.active').parents('.year-link').find('a').first().addClass('active');
      $('.year-link').parent().find('.active').parents('.collapsible').toggleClass('collapsed');

      $('.year-link+.item-list ul a').click( function (e) {
        e.stopPropagation();
      });
    }
  };

  Drupal.behaviors.equalizeBoxes = {
    attach: function () {
      $(window).resize(function() {
        delay(function(){
          var equalizeBoxes = $('.block-content-bottom').find('.panel-panel');
          Drupal.theme('equalizeheight', equalizeBoxes);
        }, 250);
      });

      $(window).trigger('resize');
    }
  };

  /**
   * Responsive nav menu
   */
  Drupal.behaviors.toggleNav = {

    attach: function() {

      $.fn.slideUpTransition = function() {
        return this.each(function() {
          var $el = $(this);

          // Trigger the slide up transition.
          $el.css('max-height', '0')
            .removeClass('is-expanded');
        });
      };

      $.fn.slideDownTransition = function() {
        return this.each(function() {
          var $el = $(this);

          // Temporarily make the element visible to get the size.
          $el.css('max-height', 'none');
          var height = $el.outerHeight();

          // Hide the element again.
          $el.css('max-height', '0');

          // Trigger the slide down transition.
          setTimeout(function() {
            $el.css('max-height', height)
              .addClass('is-expanded');
          }, 1);
        });
      };

      $.fn.toggleSlideTransition = function() {
        return this.each(function() {

          var $el = $(this);

          if ($el.hasClass('is-expanded')) {
            $el.slideUpTransition();
          } else {
            $el.slideDownTransition();
          }
        });
      };

      function toggleAttr( index, val ) {
        return val !== 'true';
      }

      // Make sure the nav menu block exists.
      var $navMenuBlock = $('#block-menu-block-1');

      if (!$navMenuBlock.length) {
        return;
      }

      // Hide / show the nav menu when the toggle button is clicked.
      var $toggleButton = $navMenuBlock.siblings('.responsive-menu-button').first();

      if ($toggleButton.length) {

        $toggleButton.on('click', function(event) {
          event.preventDefault();

          $navMenuBlock.toggleSlideTransition();
          $toggleButton.toggleClass('active').attr('aria-expanded', toggleAttr);
        });
      }

      // Toggle sub-menus when the parent menu item is clicked.
      var $menuItems = $navMenuBlock.find('.menu-block-wrapper > .menu > li > a');

      if ($menuItems.length) {

        $menuItems.on('click', function (event) {
          if ($('.responsive-menu-button').is(':visible')) {

            var $menu = $(event.currentTarget).siblings('.menu');

            if ($menu.length) {
              event.preventDefault();

              var menuBlockHeight = $navMenuBlock.outerHeight();

              if ($menu.hasClass('is-expanded')) {
                menuBlockHeight -= $menu.outerHeight();
              } else {
                $menu.css('max-height', 'none');
                menuBlockHeight += $menu.outerHeight();
                $menu.css('max-height', '0');
              }

              $navMenuBlock.css('max-height', menuBlockHeight);

              $menu.toggleSlideTransition()
                .parent()
                .attr('aria-expanded', toggleAttr)
                .siblings()
                .removeClass('is-expanded')
                .attr('aria-expanded', false)
                .find('.menu')
                .slideUpTransition();
            }
          }
        });
      }
    }
  };

  Drupal.theme.prototype.propelresourceBreadcrumbUpdate = function (filterForm) {
    var $filterForm = filterForm;
    var $breadcrumb = $('.breadcrumb');

    $breadcrumb.html('');
    var type = $filterForm.find('.views-widget-filter-field_propel_type_target_id :selected');
    var keywords = $filterForm.find('.views-widget-filter-title input');
    $breadcrumb.append('<li>' + type.text() + '</li>');

    if (keywords.val() != '') {
      $breadcrumb.append('<li>Keywords: ' + keywords.val() + '</li>');
    }
  };

  Drupal.behaviors.breadcrumbs = {
    attach: function () {
	  if($(".view-propel-resource").length > 0){
		var $filterForm = $('.view-filters');
		var typeQuery = getQueryVariable("type");

        if(typeQuery) {
          Drupal.theme('propelresourceBreadcrumbUpdate', $filterForm);
        }

		$filterForm.once('filter-submit', function() {
          $filterForm.find('.form-submit').click( function() {
            Drupal.theme('propelresourceBreadcrumbUpdate', $filterForm);
          });
        });
	  }
	}
  };
 Drupal.theme.prototype.fileDownloadButton = function (target) {
    var file = $(target).find('.file');
    var href = file.find('a').attr('href');
    $(file).after('<div class="button"><a download="' + href + '" href="' + href + '">Download</a></div>');
  };
  Drupal.behaviors.addDownloadButton = {
    attach: function () {
      $('.styled-download').each(function( index ) {
        Drupal.theme('fileDownloadButton', $(this));
      });
    }
  };
})(jQuery);

var delay = (function(){
  var timer = 0;
  return function(callback, ms){
    clearTimeout (timer);
    timer = setTimeout(callback, ms);
  };
})();

function getQueryVariable(variable) {
  var query = window.location.search.substring(1);
  var vars = query.split("&");
  for (var i=0;i<vars.length;i++) {
    var pair = vars[i].split("=");
    if(pair[0] == variable){return pair[1];}
  }
  return(false);
}
