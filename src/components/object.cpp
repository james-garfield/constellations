#include "raylib.h"
#include "object.hpp"

void Object::ShowRectangle(Color color)
{
    DrawRectangle(this->position.x, this->position.y, this->size.x, this->size.y, color);
}

void Object::SetSize(Vector2 size)
{
    this->size = size;
}

void Object::SetPosition(Vector2 position)
{
    this->position = position;
}