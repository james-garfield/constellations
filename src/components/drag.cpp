#include "raylib.h"
#include "drag.hpp"
#include <iostream>

void Drag::Draw()
{
    // DrawTexture
    DrawTexture(this->texture, this->position.x, this->position.y, WHITE);
}

void Drag::Update()
{
    // Set the height and width of the texture.
    this->texture.height = this->size.y;
    this->texture.width = this->size.x;

    // Check if the mouse is over the Drag object
    if (this->isMouseOver())
    {
        // Check if the left mouse button is pressed
        if (IsMouseButtonDown(MOUSE_LEFT_BUTTON))
        {
            this->isDragging = true;
        }
    }
    // Check if the left mouse button is released
    if (IsMouseButtonUp(MOUSE_LEFT_BUTTON))
    {
        this->isDragging = false;
    }

    // If dragging, update the position to the mouse position
    if (this->isDragging)
    {
        // Center the image on the actual mouse pointer.
        Vector2 mousePosition = GetMousePosition();
        mousePosition.x -= this->size.x / 2;
        mousePosition.y -= this->size.y / 2;

        this->SetPosition(mousePosition);
    }
}

bool Drag::isMouseOver()
{
    Vector2 mousePosition = GetMousePosition();
    return CheckCollisionPointRec(mousePosition, {this->position.x, this->position.y, this->size.x, this->size.y});
}

void Drag::SetTexture(const char *filename)
{
    // if the current texture is not empty unload it
    if (this->texture.id != 0)
    {
        UnloadTexture(this->texture);
    }

    std::cout << "Loading Texture " << filename << "\n";
    // LoadTexture
    this->texture = LoadTexture(filename);

    // If the texture is not loaded, print error
    if (this->texture.id == 0)
    {
        std::cout << "Error loading texture " << filename << "\n";
    }
}