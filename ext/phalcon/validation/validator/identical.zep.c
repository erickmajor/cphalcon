
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
#include "kernel/array.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
/**
 * Phalcon\Validation\Validator\Identical
 *
 * Checks if a value is identical to other
 *
 * <code>
 * use Phalcon\Validation;
 * use Phalcon\Validation\Validator\Identical;
 *
 * $validator = new Validation();
 *
 * $validator->add(
 *     "terms",
 *     new Identical(
 *         [
 *             "accepted" => "yes",
 *             "message" => "Terms and conditions must be accepted",
 *         ]
 *     )
 * );
 *
 * $validator->add(
 *     [
 *         "terms",
 *         "anotherTerms",
 *     ],
 *     new Identical(
 *         [
 *             "accepted" => [
 *                 "terms"        => "yes",
 *                 "anotherTerms" => "yes",
 *             ],
 *             "message" => [
 *                 "terms"        => "Terms and conditions must be accepted",
 *                 "anotherTerms" => "Another terms  must be accepted",
 *             ],
 *         ]
 *     )
 * );
 * </code>
 */
ZEPHIR_INIT_CLASS(Phalcon_Validation_Validator_Identical) {

	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Validation\\Validator, Identical, phalcon, validation_validator_identical, phalcon_validation_validator_ce, phalcon_validation_validator_identical_method_entry, 0);

	return SUCCESS;

}

/**
 * Executes the validation
 */
PHP_METHOD(Phalcon_Validation_Validator_Identical, validate) {

	zend_bool valid = 0;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *validation, validation_sub, *field, field_sub, message, label, replacePairs, value, accepted, valueOption, code, _0, _1, _2$$3, _3$$4, _4$$5, _5$$5, _6$$6, _7$$7, _8$$8, _9$$8, _10$$8;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&validation_sub);
	ZVAL_UNDEF(&field_sub);
	ZVAL_UNDEF(&message);
	ZVAL_UNDEF(&label);
	ZVAL_UNDEF(&replacePairs);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&accepted);
	ZVAL_UNDEF(&valueOption);
	ZVAL_UNDEF(&code);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_4$$5);
	ZVAL_UNDEF(&_5$$5);
	ZVAL_UNDEF(&_6$$6);
	ZVAL_UNDEF(&_7$$7);
	ZVAL_UNDEF(&_8$$8);
	ZVAL_UNDEF(&_9$$8);
	ZVAL_UNDEF(&_10$$8);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &validation, &field);



	ZEPHIR_CALL_METHOD(&value, validation, "getvalue", NULL, 0, field);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "accepted");
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "hasoption", NULL, 0, &_1);
	zephir_check_call_status();
	if (zephir_is_true(&_0)) {
		ZEPHIR_INIT_VAR(&_2$$3);
		ZVAL_STRING(&_2$$3, "accepted");
		ZEPHIR_CALL_METHOD(&accepted, this_ptr, "getoption", NULL, 0, &_2$$3);
		zephir_check_call_status();
		if (Z_TYPE_P(&accepted) == IS_ARRAY) {
			zephir_array_fetch(&_3$$4, &accepted, field, PH_NOISY | PH_READONLY, "phalcon/validation/validator/identical.zep", 73 TSRMLS_CC);
			ZEPHIR_CPY_WRT(&accepted, &_3$$4);
		}
		valid = ZEPHIR_IS_EQUAL(&value, &accepted);
	} else {
		ZEPHIR_INIT_VAR(&_5$$5);
		ZVAL_STRING(&_5$$5, "value");
		ZEPHIR_CALL_METHOD(&_4$$5, this_ptr, "hasoption", NULL, 0, &_5$$5);
		zephir_check_call_status();
		if (zephir_is_true(&_4$$5)) {
			ZEPHIR_INIT_VAR(&_6$$6);
			ZVAL_STRING(&_6$$6, "value");
			ZEPHIR_CALL_METHOD(&valueOption, this_ptr, "getoption", NULL, 0, &_6$$6);
			zephir_check_call_status();
			if (Z_TYPE_P(&valueOption) == IS_ARRAY) {
				zephir_array_fetch(&_7$$7, &valueOption, field, PH_NOISY | PH_READONLY, "phalcon/validation/validator/identical.zep", 80 TSRMLS_CC);
				ZEPHIR_CPY_WRT(&valueOption, &_7$$7);
			}
			valid = ZEPHIR_IS_EQUAL(&value, &valueOption);
		}
	}
	if (!(valid)) {
		ZEPHIR_CALL_METHOD(&label, this_ptr, "preparelabel", NULL, 0, validation, field);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_8$$8);
		ZVAL_STRING(&_8$$8, "Identical");
		ZEPHIR_CALL_METHOD(&message, this_ptr, "preparemessage", NULL, 0, validation, field, &_8$$8);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&code, this_ptr, "preparecode", NULL, 0, field);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&replacePairs);
		zephir_create_array(&replacePairs, 1, 0 TSRMLS_CC);
		zephir_array_update_string(&replacePairs, SL(":field"), &label, PH_COPY | PH_SEPARATE);
		ZEPHIR_INIT_NVAR(&_8$$8);
		object_init_ex(&_8$$8, phalcon_messages_message_ce);
		ZEPHIR_CALL_FUNCTION(&_9$$8, "strtr", NULL, 50, &message, &replacePairs);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_10$$8);
		ZVAL_STRING(&_10$$8, "Identical");
		ZEPHIR_CALL_METHOD(NULL, &_8$$8, "__construct", NULL, 302, &_9$$8, field, &_10$$8, &code);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, validation, "appendmessage", NULL, 0, &_8$$8);
		zephir_check_call_status();
		RETURN_MM_BOOL(0);
	}
	RETURN_MM_BOOL(1);

}

