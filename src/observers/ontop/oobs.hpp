#pragma once

#include "ios.hpp"
#include "drag.hpp"
#include <vector>

class OnTopObserver : public IObserver
{
public:
    void Update() override; 
    /**
     * The known drags.
    */
    std::vector<Drag> drags;
};