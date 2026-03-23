<?php
// Count Vowels in a String
$string = "Hello World";
$vowels = 0;
$vowel_list = "aeiouAEIOU";

for ($i = 0; $i < strlen($string); $i++) {
    if (strpos($vowel_list, $string[$i]) !== false) {
        $vowels++;
    }
}

echo "String: '$string'\n";
echo "Number of vowels: $vowels\n";
?>
