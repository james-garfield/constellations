#pragma once

#include "raylib.h"
#include "object.hpp"

class Collider : public Object
{
public:
    /**
     * Check collision
     */
    bool CheckCollision(Collider &other);

    /**
     * Check is mouse over said object.
     */
    bool IsMouseOver();

    // /**
    //  * Handle collision with another object
    //  */
    // virtual void OnCollision(Collider &other) = 0;
};