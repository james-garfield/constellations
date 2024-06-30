// const CONTEXT_MENU_ID = "contextMenu";

// function hideMenu() {
//     document.getElementById(CONTEXT_MENU_ID).style.display = "none";
// }

// function rightClick(e) {
//     e.preventDefault();

//     // Check if wer are already showing the menu.
//     if (document.getElementById(CONTEXT_MENU_ID).style.display == "block") {
//         hideMenu();
//     } else {
//         let menu = document.getElementById(CONTEXT_MENU_ID);

//         menu.style = "block";
//         menu.style.left = e.pageX + "px";
//         menu.style.top = e.pageY + "px";
//     }
// }

// document.onclick = hideMenu;
// document.oncontextmenu = rightClick;