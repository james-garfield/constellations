#pragma once

#include "raylib.h"
#include "collider.hpp"
#include <string>

class Drag : public Collider
{
public:
    void Init(Vector2 position, Vector2 size, std::string filename);

    /**
     * Updates the Drag object state.
     */
    void Update() override;
    /**
     * Draws the Drag object.
     */
    void Draw() override;

    /**
     * Is the object currently being dragged?
     */
    bool IsDragging() { return this->isDragging; }

    /**
     * Is the object active. Not to be confused with IsDragging.
     */
    bool IsActive() { return this->isActive; }

    /**
     * Is the object being resized?
     */
    bool IsResizing() { return this->isResizing; }

    /**
     * Get the z index of said drag.
     */
    int GetZIndex() const { return this->zIndex; }

    bool GetIsDragging() const { return this->isDragging; }
    bool GetIsActive() const { return this->isActive; }
    bool GetIsResizing() const { return this->isResizing; }

    /**
     * Set the z index of said drag.
     */
    void SetZIndex(int zIndex) { this->zIndex = zIndex; }

    /**
     * Set isActive
     */
    void SetIsActive(bool isActive) { this->isActive = isActive; }

    /**
     * Set isDragging.
     */
    void SetIsDragging(bool isDragging) { this->isDragging = isDragging; }

    /**
     * Set isResizing.
     */
    void SetIsResizing(bool isResizing) { this->isResizing = isResizing; }

    bool operator==(const Drag &other) const { return this->texture.id == other.texture.id; }

    /**
     * Move with mouse.
     */
    void MoveWithMouse();

    /**
     * Is the object colliding with itself?
    */
    bool IsCollidingWithSelf(std::vector<Drag> &dragObjects);

private:
    /**
     * Is the object currently being dragged?
     */
    bool isDragging = false;

    /**
     * Draw the 4 points of the rectangle. To be used for resizing.
     */
    void drawPoints();

    /**
     * Is the object active. Not to be confused with isDragging.
     */
    bool isActive = false;

    /**
     * Is the object being resized?
     */
    bool isResizing = false;

    /**
     * The z index of the drag.
     */
    int zIndex = 0;
};
