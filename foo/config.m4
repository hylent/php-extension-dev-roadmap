PHP_ARG_ENABLE(foo, whether to enable foo support,
[  --enable-foo           Enable foo support])

if test "$PHP_FOO" != "no"; then
  PHP_NEW_EXTENSION(foo, foo.c, $ext_shared)
fi
