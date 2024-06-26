import { loadImages } from "./load_images.js";
import images from "./images.js";
import { loadCanvas } from "./load_canvas.js";

// Load the canvas
loadCanvas();

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

// var download = function(){
//     var link = document.createElement('a');
//     link.download = 'filename.png';
//     link.href = document.getElementById('canvas').toDataURL()
//     link.click();
// }
  
function saveCanvas() {
    const link = document.createElement('a');
    link.download = 'constellation.png';
    link.href = canvas.toDataURL();
    link.click();
}
function resetCanvas() {
    loadCanvas();
}

document.getElementById("saveButton").onclick = saveCanvas;
document.getElementById("cancelButton").onclick = resetCanvas;
