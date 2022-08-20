(function ($) {

  Drupal.behaviors.modifyAriticlesViewsExposedFormLinks = {
    attach: function (context, settings) {
      $('#views-exposed-form-articles-page-2 ', context).find('input[name="body_value"]').on('keyup', function () {
        let field_value = $(this).val();
        modifyExposedFormLinks(field_value);
      });

      function modifyExposedFormLinks(field_value) {
        $('#views-exposed-form-articles-page-2', context).find('.bef-select-as-links .form-type-bef-link > a').each(function (index, element) {
          let href = $(element).attr('href');
          let new_href = href.replace(/(&body_value=).*(&.+)/, '$1' + encodeURIComponent(field_value) + '$2');
          $(element).attr('href', new_href);
        });
      }
    }
  };
})(jQuery);
