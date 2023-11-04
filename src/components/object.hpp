#pragma once

#include "raylib.h"

class Object
{
protected:
    /**
     * The position of the object.
    */
    Vector2 position;
    /**
     * The size of the object.
    */
    Vector2 size;

public:
    /**
     * Change size of the Drag image.
     */
    virtual void SetSize(Vector2 size);
    /**
     * Set position.
     */
    virtual void SetPosition(Vector2 position);

        /**
     * Updates the Drag object state.
     */
    virtual void Update() = 0;
    /**
     * Draws the Drag object.
     */
    virtual void Draw() = 0;
    /**
     * Show the object's representation on the screen.
     */
    void ShowRectangle(Color color);
};