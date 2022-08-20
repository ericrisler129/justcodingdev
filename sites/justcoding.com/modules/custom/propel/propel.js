(function ($) {

/*Select all values in company field. Should add field_select_all in content type*/
  Drupal.behaviors.selectAllCompanies = {
	attach: function() {
	  $('#edit-field-select-all-und').click(function () {
        $(this).is(':checked') ? $('.field-name-field-owner-company .form-checkbox').attr('checked', true) : $('.form-checkbox').attr('checked', false);
      });
	}
  };

})(jQuery);
