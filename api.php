<?php

header("Cross-Origin-Opener-Policy: same-origin");
header("Cross-Origin-Embedder-Policy: require-corp");

function endsWith($haystack, $needle) {
    return substr_compare($haystack, $needle, -strlen($needle)) === 0;
}

// Make request for all image paths
if ($_GET['method'] == "images") {
    // Read images in assets/images
    $images = [];
    $dir = "assets/images";

    if (is_dir($dir)) {
        if ($dh = opendir($dir)) {
            while (($file = readdir($dh)) !== false) {
                if (!endsWith($file, ".png") and !endsWith($file, ".jpg")) {
                    continue;
                }
                $images[] = $dir . "/" . $file;
            }
            closedir($dh);
        }
    }

    echo json_encode($images);
}
