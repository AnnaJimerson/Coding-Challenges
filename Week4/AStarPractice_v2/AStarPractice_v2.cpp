// AStarPractice_v2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Grid.h"
#include "vld.h"

int main()
{
    Grid grid(10, 10);
    grid.SetStartPoint(2, 2);
    grid.SetEndPoint(8, 8);

    grid.GenerateGrid();

    // Delta between each from to be displayed
    int frameDeltaMax = 990000000;
    int frameDelta = 0;

    while (frameDelta != -1) {
        // Increase frame delta to progress each frame
        (frameDelta < frameDeltaMax) ? frameDelta++ : frameDelta = 0;
        // Check if on frame to update
        if (frameDelta != 0) continue;

        // Then do logic for the frame
        grid.Update();
    }
}
