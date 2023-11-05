#pragma once

#include "raylib.h"
#include "drag.hpp"
#include "collider.hpp"
#include <string>

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
     * Will be NULL if empty. If not empty, load into window and delete from this.
     */
    Drag* child = NULL;
    
};