<?php
class Demo {
    public function __construct() {
        echo "Constructor called.<br>";
    }

    public function show() {
        echo "Object is working.<br>";
    }

    public function __destruct() {
        echo "Destructor called.<br>";
    }
}

$obj = new Demo();
$obj->show();
?>
