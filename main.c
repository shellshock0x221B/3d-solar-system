#include <raylib.h>
#include "elements.h"



    
    int main(){

        InitWindow(1400, 800, "genrale grv emu");

        Camera cam = {0};
        cam.position =(Vector3) {10.0f, 50.0f , -50.0f};
        cam.target = (Vector3) {0.0f , 0.0f , 0.0f};
        cam.up = (Vector3) {0.0f , 1.0f , 0.0f};
        cam.fovy = 45.0f;
        cam.projection = CAMERA_PERSPECTIVE;
        Vector3 spherepos = (Vector3){0.0f , 0.0f , 0.0f};

ToggleFullscreen();
        createObjects();

        SetTargetFPS(60);
        DisableCursor();

        while (!WindowShouldClose()) {
            updatePhysics();
            ClearBackground(BLACK);
            UpdateCamera(&cam, CAMERA_FREE);
            BeginDrawing();
            BeginMode3D(cam);
            
            drawObjects();
            DrawWarpedGrid(sun, planet, earth,planet1);

            EndMode3D();
            EndDrawing();

        
        }


        return 0;

    }