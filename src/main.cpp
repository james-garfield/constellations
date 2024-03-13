
#include "raylib.h"
#include "drag.hpp"
#include "drag_icon.hpp"

#include <iostream>
#include <vector>
#include <string>
#include <filesystem>
#include <emscripten/fetch.h>

namespace fs = std::filesystem;

std::vector<DragIcon> dragIcons;
std::vector<Drag> dragObjects;

void InitDragIcons();
void UpdateDragLogic();
bool IsMouseOverADragObject();

//------------------------------------------------------------------------------------
// Program main entry point
//------------------------------------------------------------------------------------
int main(void)
{
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "Constellations");

    SetTargetFPS(60); // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------

    // Allow user to resize window
    // NOTE: This functionality is not available on Android or HTML5 platforms
    SetWindowState(FLAG_WINDOW_RESIZABLE);

    InitDragIcons();

    // Main game loop
    while (!WindowShouldClose()) // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------
        UpdateDragLogic();
        for (auto &drag : dragObjects)
        {
            drag.Update();
        }

        for (auto &dragIcon : dragIcons)
        {
            dragIcon.Update();
            // If our dragIcon has a child, add it to the dragObjects vector and delete the child.
            if (dragIcon.child != NULL)
            {
                dragObjects.push_back(*dragIcon.child);
                dragIcon.child = NULL;
            }
        }

        //----------------------------------------------------------------------------------

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

        ClearBackground(RAYWHITE);

        // Draw the drag objects
        for (auto &dragObject : dragObjects)
        {
            dragObject.Draw();
        }
        for (auto &dragIcon : dragIcons)
        {
            dragIcon.Draw();
        }

        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow(); // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}

void imageListDownloadSucceeded(emscripten_fetch_t *fetch) {
    printf("Finished downloading %llu bytes from URL %s.\n", fetch->numBytes, fetch->url);
    // The data is now available at fetch->data[0] through fetch->data[fetch->numBytes-1];
    
    std::vector<std::string> imageUrls;

    emscripten_fetch_close(fetch); // Free data associated with the fetch.
}

void InitDragIcons()
{
    std::vector<std::string> imageBytes;

    // Make API calls
    std::cout << "From EMSCRIPTEN" << std::endl;

    emscripten_fetch_attr_t attr;
    emscripten_fetch_attr_init(&attr);
    strcpy(attr.requestMethod, "GET");
    attr.attributes = EMSCRIPTEN_FETCH_LOAD_TO_MEMORY;
    attr.onsuccess = imageListDownloadSucceeded;
    emscripten_fetch(&attr, "http://localhost:8080/api.php?method=images"); // Blocks here until the operation is complete.
    // if (fetch->status == 200) {
    //     printf("Finished downloading %llu bytes from URL %s.\n", fetch->numBytes, fetch->url);
    //     // The data is now available at fetch->data[0] through fetch->data[fetch->numBytes-1];
    // } else {
    //     printf("Downloading %s failed, HTTP failure status code: %d.\n", fetch->url, fetch->status);
    // }

    int startX = 10;
    int startY = 10;
    int columns = 2;

    for (int i = 0; i < imageBytes.size(); i++)
    {
        Vector2 size = {100, 100};

        // Based on columns and rows, calculate position
        Vector2 position = {startX + (size.x * (i % columns)), startY + (size.y * (i / columns))};

        DragIcon *icon = new DragIcon(position, size, imageBytes[i]);

        dragIcons.push_back(*icon);

        delete icon;
    }

    for (auto &dragIcon : dragIcons)
    {
        std::cout << dragIcon.filename << std::endl;
    }
}

void UpdateDragLogic()
{
    if (IsMouseButtonDown(MOUSE_BUTTON_LEFT))
    {
        // Check if any Drag object is currently being dragged
        for (auto &drag : dragObjects)
        {
            if (drag.IsDragging())
            {
                // End the UpdateDragLogic call.
                return;
            }
        }

        // Check if mouse is over, if not, set all drags to active false
        if (!IsMouseOverADragObject())
        {
            for (auto &drag : dragObjects)
            {
                drag.SetIsActive(false);
            }

            // End update call.
            return;
        }

        int indexOfOrder = -1;
        for (int i = dragObjects.size() - 1; i > -1; i--)
        {
            if (!dragObjects[i].IsMouseOver())
            {
                continue;
            }

            dragObjects[i].SetIsDragging(true);
            dragObjects[i].SetIsActive(true);

            // Unactivate all other drags.
            for (auto &drag : dragObjects)
            {
                if (drag == dragObjects[i])
                {
                    continue;
                }

                drag.SetIsActive(false);
            }

            // Re order drags
            indexOfOrder = i;
            break;
        }

        // If index is greater than 0, re-order the vector
        if (indexOfOrder != -1)
        {
            std::vector<Drag> newDragObjects = dragObjects;
            newDragObjects[dragObjects.size() - 1] = dragObjects[indexOfOrder];
            newDragObjects[indexOfOrder] = dragObjects[dragObjects.size() - 1];

            // Update dragObjects
            dragObjects = newDragObjects;
        }
    }
    else
    {
        for (auto &drag : dragObjects)
        {
            drag.SetIsDragging(false);
        }
    }
}

/**
 * @brief Is the mouse currently over a Drag object?
 *
 * @return true
 * @return false
 */
bool IsMouseOverADragObject()
{
    for (auto &drag : dragObjects)
    {
        if (drag.IsMouseOver())
        {
            return true;
        }
    }

    return false;
}