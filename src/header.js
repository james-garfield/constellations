function hideOptionsMenu() {
    const contextButtons = document.getElementsByClassName("contextButton");
    for (const button of contextButtons) {
        button.style = "opacity: 0.5";
        button.disabled = true;
    }
}

function showOptionsMenu() {
    const contextButtons = document.getElementsByClassName("contextButton");
    for (const button of contextButtons) {
        button.style = "opacity: 1";
        button.disabled = false;
    }
}

function showTextOptionsMenu() {
    showOptionsMenu();
    const textContextButtons = document.getElementsByClassName("textContextButton");
    for (const button of textContextButtons) {
        button.style = "opacity: 1";
        button.disabled = false;
    }
}

function hideTextOptionsMenu() {
    const textContextButtons = document.getElementsByClassName("textContextButton");
    for (const button of textContextButtons) {
        button.style = "opacity: 0.5";
        button.disabled = true;
    }
}

function changeFont(font) {
    console.log("Called");
    let activeObject = window.fCanvas.getActiveObject();
    if (activeObject) {
        activeObject.set('fontFamily', font);
        activeObject.setCoords(); // Update coordinates and dimensions
        window.fCanvas.renderAll();
    }
}