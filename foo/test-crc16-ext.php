<?php

$ts = microtime(true);

$i = 10000;

while (--$i >= 0) {
    $r = foo_crc16($i);
}

echo sprintf(
    '%0.6fs, %0.6fM',
    microtime(true) - $ts,
    memory_get_peak_usage() / (1 << 20)
), PHP_EOL;

