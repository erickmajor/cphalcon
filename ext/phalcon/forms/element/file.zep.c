
#ifdef HAVE_CONFIG_H
#include "../../../ext_config.h"
#endif

#include <php.h>
#include "../../../php_ext.h"
#include "../../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/fcall.h"
#include "kernel/memory.h"
#include "kernel/operators.h"


/**
 * Phalcon\Forms\Element\File
 *
 * Component INPUT[type=file] for forms
 */
ZEPHIR_INIT_CLASS(Phalcon_Forms_Element_File) {

	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Forms\\Element, File, phalcon, forms_element_file, phalcon_forms_element_ce, phalcon_forms_element_file_method_entry, 0);

	return SUCCESS;

}

/**
 * Renders the element widget returning html
 */
PHP_METHOD(Phalcon_Forms_Element_File, render) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;
	zval *attributes_param = NULL, _1;
	zval attributes;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&attributes);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &attributes_param);

	if (!attributes_param) {
		ZEPHIR_INIT_VAR(&attributes);
		array_init(&attributes);
	} else {
		zephir_get_arrval(&attributes, attributes_param);
	}


	ZEPHIR_CALL_METHOD(&_1, this_ptr, "prepareattributes", NULL, 0, &attributes);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_CE_STATIC(phalcon_tag_ce, "filefield", &_0, 0, &_1);
	zephir_check_call_status();
	RETURN_MM();

}

