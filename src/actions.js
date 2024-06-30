// This file handles the options menu actions logic
document.getElementById("copyButton").onclick = (e) => {
    // TODO
};

document.getElementById("deleteButton").onclick = (e) => {
    window.fCanvas.remove(window.fCanvas.getActiveObject());
    window.optionsMenu.style = "opacity: 0";
};

document.getElementById("bringForwardButton").onclick = (e) => {

};

document.getElementById("sendBackwardButton").onclick = (e) => {

};