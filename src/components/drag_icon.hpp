#pragma once

#include "raylib.h"
#include "drag.hpp"
#include "collider.hpp"
#include <string>

/**
 * These are the icons a user clicks on to populate the canvas.
 */
class DragIcon : public Collider 
{
public:
    DragIcon(Vector2 position, Vector2 size, std::string filename);

    /**
     * Updates the Drag object state.
     */
    void Update() override;
    /**
     * Draws the Drag object.
     */
    void Draw() override;

    /**
     * The child is only used at one moment! When the DragIcon is pressed, a Drag is created and loaded into 
     * the scene through this child pointer.
     */
    Drag* child = NULL;
    
};