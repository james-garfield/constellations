/**
 * Load images into the DOM
 */
const loadImages = async (images, size, ending, dir) => {
    const row = document.createElement("div");
    row.className = "row horizontal"

    // Add images and use index is important
    for (let i = 0; i < images.length; i++) {
        const col = document.createElement("div");
        col.className = "col image-padding";
        // Initate dom element
        const imageElement = document.createElement("img");
        // If empty, add a blank image
        if (images[i] === "") {
            imageElement.style = "opacity: 0";
            col.appendChild(imageElement);
            row.appendChild(col);
            continue;
        }
        
        // Add the image
        imageElement.src = "/assets/images/" + dir + "/" + images[i] + ending;
        imageElement.width = size.width;
        imageElement.height = size.height;
        imageElement.onclick = () => {
            fabric.Image.fromURL(imageElement.src, (oImg) => {
                oImg.scaleToWidth(size.width * 2);
                oImg.scaleToHeight(size.height * 2);
                window.fCanvas.add(oImg);
            });

        };

        // Append to body
        col.appendChild(imageElement);
        row.appendChild(col);
    }

    document.getElementById("images").appendChild(row);

};

export {
    loadImages
};
