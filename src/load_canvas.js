const loadCanvas = () => {
    // The canvas document object
    var canvas = document.getElementById('canvas');
    canvas.width = 1000;
    canvas.height = 1000;

    // The fabric canvas object
    const fCanvas = new fabric.Canvas('canvas');
    window.fCanvas = fCanvas;

    // Load the "CIRCULOS" image as a background
    fabric.Image.fromURL('./assets/images/CIRCULOS.jpg', (oImg) => {
        oImg.scaleToHeight(canvas.height, true);
        oImg.scaleToWidth(canvas.width, true);
        fCanvas.setBackgroundImage(oImg, fCanvas.renderAll.bind(fCanvas));
    });

    // Add a object slected listener
    fCanvas.on('mouse:down', function (e) {
        const obj = fCanvas.getActiveObject();
        // Check if we have an active object
        if (obj !== undefined && obj !== null) {
            // SHOW THE OPTIONS
            showOptionsMenu();
            console.log(obj.get('type'));
            if (obj.get('type') === 'textbox') {
                // Show the text meny options as well
                showTextOptionsMenu();
            } else {
                hideTextOptionsMenu();
            }
        } else {
            // HIDE THE OPTIONS
            hideOptionsMenu();
            hideTextOptionsMenu();
        }
    })
}

export { loadCanvas }