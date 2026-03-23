<?php
// Square of Numbers using foreach
$numbers = array(2, 4, 6, 8, 10);

echo "Original array: ";
print_r($numbers);

echo "Squares:\n";
foreach ($numbers as $num) {
    echo "$num² = " . ($num * $num) . "\n";
}
?>
