# PHP扩展开发学习路线

* 适用场景
    闭源、加密
    计算密集
    连接三方类库
    省去一部分资源（类文件、大数组等）加载开销

* 劣势
    对于PHPer开发难度大
    各种坑

* 内核简介
    M/R init/shutdown
    内存管理
    nts/ts
    源码要点
    PHP7

* 工具
    build-essential
    ext_skel
    --enable-debug --enable-maintainer-zts
    gdb/valgrind

* 例子
    crc16

* 坑
    memory leak
    segment fault
    各版本内核兼容
    nts/ts表现不一

* zephir
    中间语言，zephir代码转化为C，再编译安装
    依赖phalcon team的一套Zend API封装
    语法类似PHP、JS
    支持PHP7

* 参考

    《PHP扩展开发及内核应用》 http://walu.cc/phpbook/preface.md
    《深入理解PHP内核》 http://www.php-internals.com/book/
    各种扩展 http://pecl.php.net/packages.php
    Yaf https://github.com/laruence/php-yaf
    Zephir http://zephir-lang.com/
    PHPCPP https://github.com/CopernicaMarketingSoftware/PHP-CPP
    Windows上编译 https://wiki.php.net/internals/windows/stepbystepbuild
    PHP7相关 http://nikic.github.io/
