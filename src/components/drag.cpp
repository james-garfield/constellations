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
    Vector2 mousePosition = GetMousePosition();
    if (mousePosition.x == this->position.x && mousePosition.y == this->position.y)
    {
        // Check if the mouse is pressed
        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON) || IsMouseButtonPressed(MOUSE_MIDDLE_BUTTON))
        {
            this->isDragging = true;
            this->SetPosition(mousePosition);
        }
    }
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