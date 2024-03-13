/**
 * Get the images we want to use for the current constellation.
 */
const getImages = async (cName) => {
    // Fetch
    const response = await fetch("http://localhost:8080/api.php?method=images");
    const images = await response.json();

    return images;
};

/**
 * Load images into the DOM
 */
const loadImages = async (images, columns) => {
    // Image data
    const size = {
        width: 100,
        height: 100,
    };

    // Add images and use index is important
    for (let i = 0; i < images.length; i++) {
        // Initate dom element
        const imageElement = document.createElement("img");
        imageElement.src = images[i];
        imageElement.width = size.width;
        imageElement.height = size.height;
        imageElement.onclick = () => {
            fabric.Image.fromURL(imageElement.src, (oImg) => {
                oImg.scaleToWidth(size.width);
                oImg.scaleToHeight(size.height);
                window.fCanvas.add(oImg);
            });
        };

        // Append to body
        document.getElementById("images").appendChild(imageElement);
    }

    // fabric.Image.fromURL()
};

export {
    getImages,
    loadImages
};