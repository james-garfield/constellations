#pragma once

#include "raylib.h"
#include "object.hpp"
#include <vector>

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