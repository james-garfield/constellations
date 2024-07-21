// This file handles the options menu actions logic
document.getElementById("copyButton").onclick = (e) => {
    // Get active object
    const obj = window.fCanvas.getActiveObject();
    obj.clone(function(clonedObj) {
        clonedObj.set({
            left: clonedObj.left + 10,
            top: clonedObj.top + 10,
            evented: true,
        });
        window.selectedImages.push(clonedObj);

        window.fCanvas.add(clonedObj);

        window.fCanvas.setActiveObject(clonedObj);
        window.fCanvas.requestRenderAll();
    });
};

document.getElementById("deleteButton").onclick = (e) => {
    window.fCanvas.remove(window.fCanvas.getActiveObject());
    hideOptionsMenu();
};

document.getElementById("bringForwardButton").onclick = (e) => {
    window.fCanvas.getActiveObject().bringForward();
};

document.getElementById("sendBackwardButton").onclick = (e) => {
    window.fCanvas.getActiveObject().sendBackwards();
};

document.getElementById("textBgColor").addEventListener('input', function (evt) {
    console.log(this.value);
    // get active fcanvas element
    let activeObject = window.fCanvas.getActiveObject();
    if (activeObject) {
        activeObject.set('backgroundColor', this.value);
        activeObject.setCoords(); // Update coordinates and dimensions
        window.fCanvas.renderAll();
    }
});
document.getElementById("textFontColor").addEventListener('input', function (evt) {
    console.log(this.value);
    // get active fcanvas element
    let activeObject = window.fCanvas.getActiveObject();
    if (activeObject) {
        activeObject.set('fill', this.value);
        activeObject.setCoords(); // Update coordinates and dimensions
        window.fCanvas.renderAll();
    }
});

document.getElementById("changeTextBGColor").onclick = (e) => {
    const textBgColorInput = document.getElementById("textBgColor");
    // Ask for color
    textBgColorInput.click();
}

document.getElementById("changeFontColor").onclick = (e) => {
    const textFontColor = document.getElementById("textFontColor");
    textFontColor.click();
}

document.getElementById("makeTransparent").onclick = (e) => {
    const activeObject = window.fCanvas.getActiveObject();
    if (activeObject) {
        activeObject.set('backgroundColor', 'transparent');
        activeObject.setCoords();
        window.fCanvas.renderAll();
    }
}