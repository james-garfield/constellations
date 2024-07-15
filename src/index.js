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
    window.optionsMenu.style = "opacity: 0";

    const link = document.createElement('a');
    link.download = 'constellation.canva';

    // convert the selectedImages into a JSON
    console.log(window.selectedImages);

    link.href = "data:text/plain;base64," + btoa(JSON.stringify(window.fCanvas.toJSON()));
    link.click();
}

function downloadCanvas() {
    // Deselect any selected images
    window.fCanvas.discardActiveObject().renderAll();
    window.optionsMenu.style = "opacity: 0";

    const link = document.createElement('a');
    link.download = 'constellation.png';
    link.href = canvas.toDataURL();
    link.click();
}

function resetCanvas() {
    window.optionsMenu.style = "opacity: 0";
    // Remove all selectedImages
    for (const image of selectedImages) {
        window.fCanvas.remove(image);
    }
    window.selectedImages = [];
}

function addText() {
    const textbox = new fabric.Textbox("Placeholder", {
        left: 0,
        top: 0,
        width: 20,
        fontSize: 20,
    })

    window.fCanvas.add(textbox).setActiveObject(textbox);
    window.optionsMenu.style = "opacity: 1";
    window.selectedImages.push(textbox);
}

async function uploadCanvas() {
    // Request from the file explorer a .canva file
    const canvaUploadInput = document.getElementById("canvaUpload");
    canvaUploadInput.click();
    const hiddenForm = document.getElementById("hiddenForm");

    let intervalId = setInterval(async function () {
        console.log("Checking for canva");
        if (canvaUploadInput.files.length > 0) {
            // Clear the current canvas
            resetCanvas();

            // We can stop our interval
            clearInterval(intervalId);
            const file = canvaUploadInput.files[0];
            hiddenForm.reset();
            canvaUploadInput.clear;
            // JSON the canva
            window.fCanvas.loadFromJSON(JSON.parse(await file.text()), function() {
                window.fCanvas.renderAll();
                window.fCanvas.getObjects().map(function(o) {
                    window.selectedImages.push(o);
                });
            });
        }
    }, 500);
}

document.getElementById("saveButton").onclick = saveCanvas;
document.getElementById("cancelButton").onclick = resetCanvas;
document.getElementById("textButton").onclick = addText;
document.getElementById("downloadButton").onclick = downloadCanvas;
document.getElementById("uploadButton").onclick = uploadCanvas;