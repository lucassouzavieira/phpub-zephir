
extern zend_class_entry *phpub_sorting_ce;

ZEPHIR_INIT_CLASS(Phpub_Sorting);

PHP_METHOD(Phpub_Sorting, hello);

ZEPHIR_INIT_FUNCS(phpub_sorting_method_entry) {
	PHP_ME(Phpub_Sorting, hello, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_FE_END
};
