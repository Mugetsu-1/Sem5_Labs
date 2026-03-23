<?php
// Array Operations
$arr1 = array("pop", "rock", "hiphop");
$arr2 = array("country", "EDM");
$choice = array("favourite" => "rock", "least_favourite" => "country");

// a) Merge operation
$merged = array_merge($arr1, $arr2);
echo "a) Merged Array:\n";
print_r($merged);

// b) Sort merged array in ascending order
sort($merged);
echo "\nb) Sorted Merged Array:\n";
print_r($merged);

// c) Sort choice array by keys then values
ksort($choice);
echo "\nc) Choice Array sorted by Keys:\n";
print_r($choice);
?>
