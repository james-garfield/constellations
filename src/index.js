import { loadImages } from "./load_images.js";
import images from "./images.js";
import { loadCanvas } from "./load_canvas.js";

window.optionsMenu = document.getElementById("optionsMenu");

// Load the canvas
loadCanvas();

window.selectedImages = [];
window.actions = [];

// Load images into the DOM
for (let i = 0; i < images.rows.length; i++) {
    loadImages(images.rows[i], {
        width: 50,
        height: 50
    }, images.ending, images.dir);
}
// Final row with arrows
loadImages(images.lastRow.row, {
    width: 50,
    height: 50
}, images.lastRow.ending, images.lastRow.dir);
  
function saveCanvas() {
    // Deselect any selected images
    window.fCanvas.discardActiveObject().renderAll();

    const link = document.createElement('a');
    link.download = 'constellation.png';
    link.href = canvas.toDataURL();
    link.click();
}
function resetCanvas() {
    window.optionsMenu.style.display = "none";
    // Remove all selectedImages
    for (const image of selectedImages) {
        window.fCanvas.remove(image);
    }
}

document.getElementById("saveButton").onclick = saveCanvas;
document.getElementById("cancelButton").onclick = resetCanvas;
