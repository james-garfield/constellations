#pragma once

#include "raylib.h"
#include "object.hpp"

class Drag : public Object
{
public:
    // No constructor or destructor needed

    /**
     * Updates the Drag object state.
     */
    void Update() override;
    /**
     * Draws the Drag object.
     */
    void Draw() override;
    /**
     * Load a texture for the Drag object.
     */
    void SetTexture(const char *filename);

private:
    /**
     * Is the object currently being dragged?
     */
    bool isDragging = false;

    /**
     * The "Image" for the Drag.
     */
    Texture2D texture;

    /**
     * Check if the mouse is over the Drag object.
    */
    bool isMouseOver();
};