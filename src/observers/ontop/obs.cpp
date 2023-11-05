#include "drag.hpp"
#include "oobs.hpp"

void OnTopObserver::Update()
{
    // Reverse iterate through the drags vector.

    for (int i = drags.size() - 1; i >= 0; i--)
    {
        if (drags[i].IsMouseOver())
        {
            // The first drag to be hovered over will be the one that is on top.
            // This is because the drags are drawn in order, so the last one drawn will be on top.
            // This is why we break out of the loop.
            drags[i].Update();
            break;
        }
    }
}