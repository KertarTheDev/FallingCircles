#pragma once

namespace NfcGameSettings
{
// Rendering parameters
    const int coordsPerVertex = 2;      // 2d vertex coordinates
    const int valuesPerColor = 3;       // RGB color format

    const int verticesPerPrimitive = 3; // Renderer interpretes vertex arrays as containing triangles

    const int samplesPerCircle = 36;    // Circle rendering quality

//Gameplay parameters
    const int gameStateUpdateInterval = 17; //milliseconds, ~60 FPS
    const int objectSpawnInterval = 200;    //milliseconds

    const int objectsSpawnedAtOnce = 1;

    const float gameFieldWidth = 1.0;
    const float gameFieldHeight = 1.5;
}
