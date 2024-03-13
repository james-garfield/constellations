import { getImages, loadImages } from "./load_images.js";

// The canvas document object
const canvas = document.getElementById('canvas');
canvas.width = window.innerWidth - 500;
canvas.height = window.innerHeight;

// The fabric canvas object
var fCanvas = new fabric.Canvas('canvas', {
    backgroundColor: '000',
});
window.fCanvas = fCanvas;

// Load images into the DOM
getImages("").then((value) => {
    console.log(value);
    loadImages(value, 2);
});

function saveCanvas() {
    const image = new Image();
    image.src = canvas.toDataURL();
    document.body.appendChild(image);
}

document.getElementById("saveButton").onclick = saveCanvas;

// const image = Image();
// image.src = canvas.toDataURL();

// document.body.appendChild(image);