const loadCanvas = () => {
    // The canvas document object
    var canvas = document.getElementById('canvas');
    canvas.width = 1000;
    canvas.height = 1000;

    // The fabric canvas object
    const fCanvas = new fabric.Canvas('canvas');
    window.fCanvas = fCanvas;

    // Load the "CIRCULOS" image as a background
    fabric.Image.fromURL('/assets/images/CIRCULOS.jpg', (oImg) => {
        oImg.scaleToHeight(canvas.height, true);
        oImg.scaleToWidth(canvas.width, true);
        fCanvas.setBackgroundImage(oImg, fCanvas.renderAll.bind(fCanvas));
    });

}

export { loadCanvas }