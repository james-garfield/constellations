#include "raylib.h"
#include "drag.hpp"
#include <iostream>
#include <string>


void Drag::Init(Vector2 position, Vector2 size, std::string filename)
{
        this->SetPosition(position);
    this->SetSize(size);
    this->SetTexture(filename);
}

void Drag::Draw()
{
    // DrawTexture
    DrawTexture(this->texture, this->position.x, this->position.y, WHITE);

    if (this->isActive || this->isResizing) 
    {
        // Draw the points
        drawPoints();
    }
}

void Drag::Update()
{
    // Set the height and width of the texture.
    this->texture.height = this->size.y;
    this->texture.width = this->size.x;

    // Check if the mouse is over the Drag object
    if (this->IsMouseOver())
    {
        // If is currently not dragging, check if the left mouse button is pressed
        if (!this->isDragging)
        {
            if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
            {
                // Check if the left mouse button is still being held down
                if (IsMouseButtonDown(MOUSE_LEFT_BUTTON))
                {
                    this->isDragging = true;
                }
            }
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

void Drag::drawPoints()
{
    // Draw 4 points on the rectangle
    DrawCircle(this->position.x, this->position.y, 5, BLACK);
    DrawCircle(this->position.x + this->size.x, this->position.y, 5, BLACK);
    DrawCircle(this->position.x, this->position.y + this->size.y, 5, BLACK);
    DrawCircle(this->position.x + this->size.x, this->position.y + this->size.y, 5, BLACK);
}