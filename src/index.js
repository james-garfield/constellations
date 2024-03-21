import { loadImages } from "./load_images.js";
import images from "./images.js";

// The canvas document object
const canvas = document.getElementById('canvas');
canvas.width = window.innerWidth - 500;
canvas.height = window.innerHeight;

// The fabric canvas object
var fCanvas = new fabric.Canvas('canvas');
window.fCanvas = fCanvas;

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
    const image = new Image();
    image.src = canvas.toDataURL();
    document.body.appendChild(image);
}

document.getElementById("saveButton").onclick = saveCanvas;
