<?php

// Convert a file to PNG from JPG
// Usage: php to_png.php <filename>

$filename = null;

if (count($argv) < 2) {
    echo "Usage: php to_png.php <filename>\n";
    exit(1);
} else {
    $filename = $argv[1];
}

if (!file_exists($filename)) {
    echo "File not found: $filename\n";
    exit(1);
}

$im = imagecreatefromjpeg($filename);
if ($im === false) {
    echo "Failed to create image from $filename\n";
    exit(1);
}

$png_filename = preg_replace('/\.jpg$/', '.png', $filename);

// saving the PNG without using DXT compression
if (!imagepng($im, $png_filename, 0)) {
    echo "Failed to write PNG file: $png_filename\n";
    exit(1);
}

echo "Wrote PNG file: $png_filename\n";