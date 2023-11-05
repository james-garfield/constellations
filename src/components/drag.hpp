#pragma once

#include "raylib.h"
#include "collider.hpp"
#include <string>

class Drag : public Collider
{
public:
    void Init(Vector2 position, Vector2 size, std::string filename);

    /**
     * Updates the Drag object state.
     */
    void Update() override;
    /**
     * Draws the Drag object.
     */
    void Draw() override;

private:
    /**
     * Is the object currently being dragged?
     */
    bool isDragging = false;

    /**
     * Draw the 4 points of the rectangle. To be used for resizing.
     */
    void drawPoints();

    /**
     * Is the object active. Not to be confused with isDragging.
     */
    bool isActive = false;

    /**
     * Is the object being resized?
     */
    bool isResizing = false;
};

