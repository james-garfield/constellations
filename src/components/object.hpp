#pragma once

#include "raylib.h"
#include <string>

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

    /**
     * The texture of the object
     */
    Texture2D texture;

public:
    /**
     * Change size of the Drag image.
     */
    void SetSize(Vector2 size);
    /**
     * Set position.
     */
    void SetPosition(Vector2 position);

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

    /**
     * Set a texture
     */
    void SetTexture(std::string filename);

    /**
     * Set a texture.
     */
    void SetTexture(Texture2D texture);

    /**
     * Textures filename.
     */
    std::string filename;

};