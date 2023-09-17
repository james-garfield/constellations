const canvas = document.getElementById('canvas');

canvas.addEventListener('dragover', (e) => {
    e.preventDefault();
});

canvas.addEventListener('drop', (e) => {
    e.preventDefault();

    const imageId = e.dataTransfer.getData('text/plain');
    const image = document.getElementById(imageId);

    if (image) {
        const clonedImage = image.cloneNode(true);
        clonedImage.classList.add('dropped-image');

        // Calculate the position of the image relative to the canvas
        const offsetX = e.clientX - canvas.getBoundingClientRect().left;
        const offsetY = e.clientY - canvas.getBoundingClientRect().top;

        clonedImage.style.left = `${offsetX}px`;
        clonedImage.style.top = `${offsetY}px`;

        canvas.appendChild(clonedImage);
    }
});

const draggableImages = document.querySelectorAll('.draggable');

draggableImages.forEach((image) => {
    image.addEventListener('dragstart', (e) => {
        e.dataTransfer.setData('text/plain', e.target.id);
    });
});
