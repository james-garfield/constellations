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

    if (this->isDragging) {
        this->MoveWithMouse();
    }
}

void Drag::MoveWithMouse()
{
    // Get the mouse position
    Vector2 mousePosition = GetMousePosition();
    mousePosition.x -= this->size.x / 2;
    mousePosition.y -= this->size.y / 2;

    this->SetPosition(mousePosition);
}

void Drag::drawPoints()
{
    // Draw 4 points on the rectangle
    DrawCircle(this->position.x, this->position.y, 5, BLACK);
    DrawCircle(this->position.x + this->size.x, this->position.y, 5, BLACK);
    DrawCircle(this->position.x, this->position.y + this->size.y, 5, BLACK);
    DrawCircle(this->position.x + this->size.x, this->position.y + this->size.y, 5, BLACK);
}

bool Drag::IsCollidingWithSelf(std::vector<Drag> &drags)
{
    for (auto &drag : drags)
    {
        if (this->CheckCollision(drag))
        {
            return true;
        }
    }
    return false;
}