<?php
class Counter {
    public static $count = 0;

    public function __construct() {
        self::$count++;
    }

    public static function total() {
        return self::$count;
    }
}

$a = new Counter();
$b = new Counter();
$c = new Counter();

echo "Total objects: " . Counter::total();
?>
