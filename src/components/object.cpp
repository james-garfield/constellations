#include "raylib.h"
#include "object.hpp"
#include <iostream>

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

void Object::SetTexture(std::string filename)
{
    // if (this->texture.id != 0)
    // {
    //     std::cout << "Unloading texture: " << this->filename << std::endl;
    //     UnloadTexture(this->texture);
    // }

    this->texture = LoadTexture(filename.c_str());

    if (this->texture.id == 0)
    {
        std::cout << "Failed to load texture: " << filename << std::endl;
    }

    this->filename = filename;
}

void Object::SetTexture(Texture2D texture)
{
    // if (this->texture.id != 0)
    // {
    //     UnloadTexture(this->texture);
    // }

    this->texture = texture;

    if (this->texture.id == 0)
    {
        std::cout << "Failed to load texture: " << texture.id << std::endl;
    }

    this->filename = "";
    // this->filename = (std::string)this->texture.id;
}