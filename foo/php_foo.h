#ifndef PHP_FOO_H
#define PHP_FOO_H

extern zend_module_entry foo_module_entry;
#define phpext_foo_ptr &foo_module_entry

#define PHP_FOO_VERSION "0.0.1"

#ifdef PHP_WIN32
#   define PHP_FOO_API __declspec(dllexport)
#elif defined(__GNUC__) && __GNUC__ >= 4
#   define PHP_FOO_API __attribute__ ((visibility("default")))
#else
#   define PHP_FOO_API
#endif

#ifdef ZTS
#include "TSRM.h"
#endif

ZEND_BEGIN_MODULE_GLOBALS(foo)
    long counter;
ZEND_END_MODULE_GLOBALS(foo)

PHP_GINIT_FUNCTION(foo);
PHP_MINIT_FUNCTION(foo);
PHP_MSHUTDOWN_FUNCTION(foo);
PHP_RINIT_FUNCTION(foo);
PHP_RSHUTDOWN_FUNCTION(foo);
PHP_MINFO_FUNCTION(foo);

#ifdef ZTS
#define FOO_G(v) TSRMG(foo_globals_id, zend_foo_globals *, v)
#else
#define FOO_G(v) (foo_globals.v)
#endif

PHP_FUNCTION(foo_counter_get);
PHP_FUNCTION(foo_counter_incr);
PHP_FUNCTION(foo_crc16);

#endif // PHP_FOO_H
