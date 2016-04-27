# PHP扩展开发学习路线

## 适用场景

* 闭源、加密
* 密集计算
* 连接三方类库
* 省去一部分资源（类文件、大数组等）加载开销

## 劣势

* 需要有C语言基础，学习、开发难度较大
* 不能完全闭源（字符串字面值、函数调用图可以被反编译出来）
* 各种坑（内存泄漏、段错误、ZendAPI版本间差异、NTS/TS表现不一）

## 内核简介

### SAPI（Server Application Programming Interface）

PHP和外界沟通的抽象层，比如通过命令行执行PHP的`cli`、通过php-fpm执行的`cgi-fcgi`等。

查看PHP源码目录`sapi/`。

### MInit/MShutdown RInit/RShutdown

![流程](/asserts/sapi.png)

### 内存管理

扩展中可以直接向系统申请内存，可以通过ZendAPI封装的相关函数进行内存操作：

```
void *malloc(size_t count);
void *emalloc(size_t count);
void *pemalloc(size_t count, char persistent);

void *calloc(size_t count);
void *ecalloc(size_t count);
void *pecalloc(size_t count, char persistent);

void *realloc(void *ptr, size_t count);
void *erealloc(void *ptr, size_t count);
void *perealloc(void *ptr, size_t count, char persistent);

void *strdup(void *ptr);
void *estrdup(void *ptr);
void *pestrdup(void *ptr, char persistent);

void free(void *ptr);
void efree(void *ptr);
void pefree(void *ptr, char persistent);
```

### 非线程安全（NTS）/线程安全（TS）

* 一般使用非线程安全版
* `Apache+mod_php5`使用线程安全版
* TS版线程间通信较快，因为共享存储空间；NTS则需要借助APC、Redis等
* TS一旦PHP扩展发生段错误，线程异常退出，会影响到服务器进程；NTS不受影响，大不了重启一下fpm进程

### 源码要点

* 变量（zval、类型标记、引用计数）
* 函数（参数、返回值）
* 数组相关
* 类、对象（类声明、对象操作、数组型的类属性的特殊处理）
* 与用户空间的PHP代码沟通（触发类自动加载器、执行PHP脚本文件等）
* 资源类型（自定义数据结构）
* INI相关
* Stream相关
* Zend OP Cache相关（可以在此阶段实现PHP代码的加密）

### PHP7

* 核心数据类型`zval`、`HashTable`等占据空间更少
* 编译器优化
* `zval`不再单独从堆上分配内存并且不自己存储引用计数，更少的内存分配、操作，更少的间接指针使用

## 工具

* 源码编译工具`build-essential`
* 编译时候加参数`--enable-debug --enable-maintainer-zts`
* 扩展源码模板生成程序`php-src/ext/ext_skel`
* C开发调试工具`gdb/valgrind`

## 例子

见附源码。

* counter
* crc16

## 坑

* 内存泄漏（fpm使用内存不断增加）
* 段错误（HTTP 500）
* 各版本内核兼容（增加宏判断、自己实现兼容层）
* NTS/TS表现不一（`convert_to_array`等）

## Zephir

* 中间语言，Zephir代码转化为C，再编译安装
* 依赖phalcon team的一套Zend API封装
* 语法类似PHP、JS
* 支持PHP7

## 参考

* 《深入理解PHP内核》 http://www.php-internals.com/book/
* 《PHP扩展开发及内核应用》 http://walu.cc/phpbook/preface.md
* 各种扩展 http://pecl.php.net/packages.php
* Yaf源码 https://github.com/laruence/php-yaf
* Zephir http://zephir-lang.com/
* PHPCPP（使用C++开发PHP扩展，不支持低版本编译器，不支持PHP7） https://github.com/CopernicaMarketingSoftware/PHP-CPP
* Windows上编译 https://wiki.php.net/internals/windows/stepbystepbuild
* PHP7相关 http://nikic.github.io/
