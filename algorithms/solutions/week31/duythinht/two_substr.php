<?php
$line = trim(fgets(STDIN));

$ab_left = strpos($line, "AB");
$ab_right = strrpos($line, "AB");
$ba_left = strpos($line, "BA");
$ba_right = strrpos($line, "BA");

if ($ab_left === false || $ba_left === false) {
  echo 'NO';
  exit(0);
}

if (abs($ab_left - $ba_left) > 1 || abs($ab_left - $ba_right) > 1 || abs($ab_right - $ba_left) > 1 || abs($ab_right - $ba_right) > 1) {
  echo 'YES';
  exit(0);
}

echo 'NO';
