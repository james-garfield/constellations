/*******************************************************************************************
 *
 *   raylib [core] example - Basic window
 *
 *   Welcome to raylib!
 *
 *   To test examples, just press F6 and execute raylib_compile_execute script
 *   Note that compiled executable is placed in the same folder as .c file
 *
 *   You can find all basic examples on C:\raylib\raylib\examples folder or
 *   raylib official webpage: www.raylib.com
 *
 *   Enjoy using raylib. :)
 *
 *   Example originally created with raylib 1.0, last time updated with raylib 1.0
 *
 *   Example licensed under an unmodified zlib/libpng license, which is an OSI-certified,
 *   BSD-like license that allows static linking with closed source software
 *
 *   Copyright (c) 2013-2023 Ramon Santamaria (@raysan5)
 *
 ********************************************************************************************/

#include "raylib.h"
#include "drag.hpp"
#include "drag_icon.hpp"
#include "oobs.hpp"

#include <iostream>
#include <vector>
#include <string>
#include <filesystem>

namespace fs = std::filesystem;

std::vector<DragIcon> dragIcons;
std::vector<Drag> dragObjects;
int zIndex = 0;
// Observerrs

void InitDragIcons();
void UpdateDragLogic();

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

void InitDragIcons()
{
    std::vector<std::string> filePaths;
    // Load images from assets folder
    fs::path directoryPath("assets/images");

    // Check if the path exists and is a directory
    if (fs::exists(directoryPath) && fs::is_directory(directoryPath))
    {
        for (const auto &entry : fs::directory_iterator(directoryPath))
        {
            if (fs::is_regular_file(entry.path()))
            {
                filePaths.push_back(entry.path().string());
            }
        }
    }
    else
    {
        std::cout << "Invalid directory path or doesn't exist." << std::endl;
    }

    int startX = 10;
    int startY = 10;
    int columns = 2;

    for (int i = 0; i < filePaths.size(); i++)
    {
        Vector2 size = {100, 100};

        // Based on columns and rows, calculate position
        Vector2 position = {startX + (size.x * (i % columns)), startY + (size.y * (i / columns))};

        DragIcon *icon = new DragIcon(position, size, filePaths[i]);

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
        for (auto &drag : dragObjects)
        {
            if (drag.IsMouseOver() && !drag.IsCollidingWithSelf(dragObjects))
            {
                drag.SetIsDragging(true);
                break;
            }
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