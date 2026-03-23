<?php
// Function Overloading using func_get_args
function sum() {
    $args = func_get_args();
    $total = 0;

    foreach ($args as $num) {
        $total += $num;
    }

    return $total;
}

echo "Sum of 2 numbers: " . sum(5, 10) . "\n";
echo "Sum of 3 numbers: " . sum(5, 10, 15) . "\n";
echo "Sum of 4 numbers: " . sum(2, 4, 6, 8) . "\n";
?>
