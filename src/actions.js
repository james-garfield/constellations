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
    window.optionsMenu.style = "opacity: 0";
};

document.getElementById("bringForwardButton").onclick = (e) => {
    window.fCanvas.getActiveObject().bringForward();
};

document.getElementById("sendBackwardButton").onclick = (e) => {
    window.fCanvas.getActiveObject().sendBackwards();
};