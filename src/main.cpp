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
#include <iostream>

Drag testImage = Drag();

//------------------------------------------------------------------------------------
// Program main entry point
//------------------------------------------------------------------------------------
int main(void)
{
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");

    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------

    // Allow user to resize window
    // NOTE: This functionality is not available on Android or HTML5 platforms
    SetWindowState(FLAG_WINDOW_RESIZABLE);

    testImage.SetSize({100, 100});
    testImage.SetPosition({screenWidth / 2, screenHeight / 2});
    testImage.SetTexture("assets/images/person.png");

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------
        testImage.Update();

        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
        {
            std::cout << "Left Mouse Button Pressed\n";
        }
        if (IsMouseButtonPressed(MOUSE_MIDDLE_BUTTON))
        {
            std::cout << "Middle Mouse Button Pressed\n";
        }
        if (IsMouseButtonPressed(MOUSE_RIGHT_BUTTON))
        {
            std::cout << "Right Mouse Button Pressed\n";
        }

        //----------------------------------------------------------------------------------

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

            ClearBackground(RAYWHITE);
            testImage.Draw();
            // testImage.ShowRectangle(BLACK);

        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}