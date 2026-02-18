#include <raylib.h>
#include "elements.h"


/*sun;
extern Object mercury;
extern Object venus;
extern Object earth;
extern Object mars;
extern Object jupiter;
extern Object saturn;
extern Object uranus;
extern Object neptune;
extern Object moon;
*/

    
    int main(){

        InitWindow(1400, 800, "genrale grv emu");

        Camera cam = {0};
        cam.position =(Vector3) { -60, 100 , 0};
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

    updatePhysics(&mercury);
    updatePhysics(&venus);
    updatePhysics(&neptune);
    updatePhysics(&uranus);
    updatePhysics(&jupiter);
    updatePhysics(&mars);
    updatePhysics(&earth);
    updatePhysics(&saturn);

    UpdateCamera(&cam, CAMERA_FREE);
    
    BeginDrawing();
    ClearBackground(BLACK);

    BeginMode3D(cam);

        drawObjects();
        DrawWarpedGrid(sun, mercury, venus, earth,
                        mars, jupiter, saturn,
                        uranus, neptune);

    EndMode3D();

    EndDrawing();
}




        return 0;

    }
