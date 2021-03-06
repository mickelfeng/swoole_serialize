/*
  +----------------------------------------------------------------------+
  | PHP Version 7                                                        |
  +----------------------------------------------------------------------+
  | Copyright (c) 1997-2016 The PHP Group                                |
  +----------------------------------------------------------------------+
  | This source file is subject to version 3.01 of the PHP license,      |
  | that is bundled with this package in the file LICENSE, and is        |
  | available through the world-wide-web at the following url:           |
  | http://www.php.net/license/3_01.txt                                  |
  | If you did not receive a copy of the PHP license and are unable to   |
  | obtain it through the world-wide-web, please send a note to          |
  | license@php.net so we can mail you a copy immediately.               |
  +----------------------------------------------------------------------+
  | Author:   woshiguo35@sina.com                                          |
  +----------------------------------------------------------------------+
 */

/* $Id$ */

#ifndef PHP_SWOOLE_SERIALIZE_H
#define PHP_SWOOLE_SERIALIZE_H

extern zend_module_entry swoole_serialize_module_entry;
#define phpext_swoole_serialize_ptr &swoole_serialize_module_entry

#define PHP_SWOOLE_SERIALIZE_VERSION "0.1.0" /* Replace with version number for your extension */

#ifdef PHP_WIN32
#define PHP_SWOOLE_SERIALIZE_API __declspec(dllexport)
#elif defined(__GNUC__) && __GNUC__ >= 4
#define PHP_SWOOLE_SERIALIZE_API __attribute__ ((visibility("default")))
#else
#define PHP_SWOOLE_SERIALIZE_API
#endif

#ifdef ZTS
#include "TSRM.h"
#endif

/*
        Declare any global variables you may need between the BEGIN
        and END macros here:

ZEND_BEGIN_MODULE_GLOBALS(swoole_serialize)
        zend_long  global_value;
        char *global_string;
ZEND_END_MODULE_GLOBALS(swoole_serialize)
 */

/* Always refer to the globals in your function as SWOOLE_SERIALIZE_G(variable).
   You are encouraged to rename these macros something shorter, see
   examples in any other php module directory.
 */
#define SWOOLE_SERIALIZE_G(v) ZEND_MODULE_GLOBALS_ACCESSOR(swoole_serialize, v)

#if defined(ZTS) && defined(COMPILE_DL_SWOOLE_SERIALIZE)

ZEND_TSRMLS_CACHE_EXTERN()
#endif



#define SERIA_SIZE    1024

#if defined(__GNUC__)
#if __GNUC__ >= 3
#define CPINLINE inline __attribute__((always_inline))
#else
#define CPINLINE inline
#endif
#elif defined(_MSC_VER)
#define CPINLINE __forceinline
#else
#define CPINLINE inline
#endif



typedef struct _seriaString {
    size_t offset;
    size_t total;
    void * buffer; //zend_string
} seriaString;

typedef struct _seriaArray {
    uint32_t nTableSize;
    uint32_t nNumUsed;
    zend_long nNextFreeElement;
} seriaArray;

#endif	/* PHP_SWOOLE_SERIALIZE_H */


#define SERIA_GET_TYPE(buffer)        *(uint32_t*) (buffer)
#define SERIA_SET_TYPE(buffer,type)   *(uint32_t*) (buffer->buffer + buffer->offset) = type


/*
 * Local variables:
 * tab-width: 4
 * c-basic-offset: 4
 * End:
 * vim600: noet sw=4 ts=4 fdm=marker
 * vim<600: noet sw=4 ts=4
 */
