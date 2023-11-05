#include "raylib.h"
#include "drag.hpp"
#include "drag_icon.hpp"
#include <string>
#include <iostream>

DragIcon::DragIcon(Vector2 position, Vector2 size, std::string filename)
{
    this->SetPosition(position);
    this->SetSize(size);

    this->SetTexture(filename);
}

void DragIcon::Update()
{
    this->texture.width = this->size.x;
    this->texture.height = this->size.y;

    // Check if mouse clicks
    if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
    {
        if (this->IsMouseOver())
        {
            Drag *newDrag = new Drag();
            // Set position to center of screen
            newDrag->SetPosition({(float)(GetScreenWidth() / 2), (float)(GetScreenHeight() / 2)});
            newDrag->SetSize({this->size.x + 10, this->size.y + 10});
            newDrag->SetTexture(this->texture);

            this->child = newDrag;
        }
    }
}

void DragIcon::Draw()
{
    // DrawTexture
    DrawTexture(this->texture, this->position.x, this->position.y, WHITE);
}
