
/* This file was generated automatically by Zephir do not modify it! */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <php.h>

#include "php_ext.h"
#include "phpub.h"

#include <ext/standard/info.h>

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/globals.h"
#include "kernel/main.h"
#include "kernel/fcall.h"
#include "kernel/memory.h"



zend_class_entry *phpub_sorting_ce;

ZEND_DECLARE_MODULE_GLOBALS(phpub)

PHP_INI_BEGIN()
	
PHP_INI_END()

static PHP_MINIT_FUNCTION(phpub)
{
	REGISTER_INI_ENTRIES();
	zephir_module_init();
	ZEPHIR_INIT(Phpub_Sorting);
	return SUCCESS;
}

#ifndef ZEPHIR_RELEASE
static PHP_MSHUTDOWN_FUNCTION(phpub)
{
	zephir_deinitialize_memory(TSRMLS_C);
	UNREGISTER_INI_ENTRIES();
	return SUCCESS;
}
#endif

/**
 * Initialize globals on each request or each thread started
 */
static void php_zephir_init_globals(zend_phpub_globals *phpub_globals TSRMLS_DC)
{
	phpub_globals->initialized = 0;

	/* Memory options */
	phpub_globals->active_memory = NULL;

	/* Virtual Symbol Tables */
	phpub_globals->active_symbol_table = NULL;

	/* Cache Enabled */
	phpub_globals->cache_enabled = 1;

	/* Recursive Lock */
	phpub_globals->recursive_lock = 0;

	/* Static cache */
	memset(phpub_globals->scache, '\0', sizeof(zephir_fcall_cache_entry*) * ZEPHIR_MAX_CACHE_SLOTS);


}

/**
 * Initialize globals only on each thread started
 */
static void php_zephir_init_module_globals(zend_phpub_globals *phpub_globals TSRMLS_DC)
{

}

static PHP_RINIT_FUNCTION(phpub)
{

	zend_phpub_globals *phpub_globals_ptr;
#ifdef ZTS
	tsrm_ls = ts_resource(0);
#endif
	phpub_globals_ptr = ZEPHIR_VGLOBAL;

	php_zephir_init_globals(phpub_globals_ptr TSRMLS_CC);
	zephir_initialize_memory(phpub_globals_ptr TSRMLS_CC);


	return SUCCESS;
}

static PHP_RSHUTDOWN_FUNCTION(phpub)
{
	
	zephir_deinitialize_memory(TSRMLS_C);
	return SUCCESS;
}

static PHP_MINFO_FUNCTION(phpub)
{
	php_info_print_box_start(0);
	php_printf("%s", PHP_PHPUB_DESCRIPTION);
	php_info_print_box_end();

	php_info_print_table_start();
	php_info_print_table_header(2, PHP_PHPUB_NAME, "enabled");
	php_info_print_table_row(2, "Author", PHP_PHPUB_AUTHOR);
	php_info_print_table_row(2, "Version", PHP_PHPUB_VERSION);
	php_info_print_table_row(2, "Build Date", __DATE__ " " __TIME__ );
	php_info_print_table_row(2, "Powered by Zephir", "Version " PHP_PHPUB_ZEPVERSION);
	php_info_print_table_end();

	DISPLAY_INI_ENTRIES();
}

static PHP_GINIT_FUNCTION(phpub)
{
	php_zephir_init_globals(phpub_globals TSRMLS_CC);
	php_zephir_init_module_globals(phpub_globals TSRMLS_CC);
}

static PHP_GSHUTDOWN_FUNCTION(phpub)
{

}


zend_function_entry php_phpub_functions[] = {
ZEND_FE_END

};

zend_module_entry phpub_module_entry = {
	STANDARD_MODULE_HEADER_EX,
	NULL,
	NULL,
	PHP_PHPUB_EXTNAME,
	php_phpub_functions,
	PHP_MINIT(phpub),
#ifndef ZEPHIR_RELEASE
	PHP_MSHUTDOWN(phpub),
#else
	NULL,
#endif
	PHP_RINIT(phpub),
	PHP_RSHUTDOWN(phpub),
	PHP_MINFO(phpub),
	PHP_PHPUB_VERSION,
	ZEND_MODULE_GLOBALS(phpub),
	PHP_GINIT(phpub),
	PHP_GSHUTDOWN(phpub),
	NULL,
	STANDARD_MODULE_PROPERTIES_EX
};

#ifdef COMPILE_DL_PHPUB
ZEND_GET_MODULE(phpub)
#endif
