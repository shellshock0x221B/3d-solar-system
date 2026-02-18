#include "elements.h"
#include <raylib.h>
#include <math.h>
#include "raymath.h"

Object sun;
Object mercury;
Object venus;
Object earth;
Object mars;
Object jupiter;
Object saturn;
Object uranus;
Object neptune;
Object moon;
void createObjects(){
    //Sun 
    sun.pos = (Vector3){0.0f , 0.0f , 0.0f};
    sun.vel = (Vector3){0.0f , 0.0f , 0.0f};
    sun.radius = 4.2;
    sun.col = YELLOW;
    sun.mass = 1000;

    //Mercury
    mercury.mass = 10;
    mercury.pos = (Vector3){10.0f, 0.0f, 0.0f};     
    mercury.vel = (Vector3){0.0f, 0.0f, 8.0f};       
    mercury.radius = 0.3;
    mercury.col = GRAY;

    //Venus
    venus.mass = 15;
    venus.pos = (Vector3){18.0f, 0.0f, 0.0f};
    venus.vel = (Vector3){0.0f, 0.0f, 5.0f};
    venus.radius = 0.5;
    venus.col = ORANGE;

    //Earth
    earth.mass = 100;
    earth.pos = (Vector3){26.0f, 0.0f, 0.0f};
    earth.vel = (Vector3){0.0f, 0.0f, 4.5f};
    earth.radius = 0.7;
    earth.col = BLUE;

    //Mars
    mars.mass = 50;
    mars.pos = (Vector3){34.0f, 0.0f, 0.0f};
    mars.vel = (Vector3){0.0f, 0.0f, 4.0f};
    mars.radius = 0.7;
    mars.col = RED;

    //Jupiter
    jupiter.mass = 300;
    jupiter.pos = (Vector3){50.0f, 0.0f, 0.0f};
    jupiter.vel = (Vector3){0.0f, 0.0f, 2.5f};
    jupiter.radius = 2.0;
    jupiter.col = BROWN;

    //Saturn
    saturn.mass = 500;
    saturn.pos = (Vector3){70.0f, 0.0f, 0.0f};
    saturn.vel = (Vector3){0.0f, 0.0f, 2.0f};
    saturn.radius = 1.8;
    saturn.col = GOLD;

    //Uranus
    uranus.mass = 300;
    uranus.pos = (Vector3){90.0f, 0.0f, 0.0f};
    uranus.vel = (Vector3){0.0f, 0.0f, 1.5f};
    uranus.radius = 1.5;
    uranus.col = SKYBLUE;

    //Neptune
    neptune.mass = 250;
    neptune.pos = (Vector3){110.0f, 0.0f, 0.0f};
    neptune.vel = (Vector3){0.0f, 0.0f, 1.2f};
    neptune.radius = 1.4;
    neptune.col = DARKBLUE;

    
}



void drawObjects(){
    DrawSphere(sun.pos , sun.radius, sun.col);
    DrawSphere(mercury.pos, mercury.radius, mercury.col);
    DrawSphere(venus.pos, venus.radius, venus.col);
    DrawSphere(earth.pos, earth.radius, earth.col);
    DrawSphere(mars.pos, mars.radius, mars.col);
    DrawSphere(jupiter.pos, jupiter.radius, jupiter.col);
    DrawSphere(saturn.pos, saturn.radius, saturn.col);
    DrawSphere(uranus.pos, uranus.radius, uranus.col);
    DrawSphere(neptune.pos, neptune.radius, neptune.col);
    
}


void DrawWarpedGrid(Object sun, Object mercury, Object venus, Object earth,
                    Object mars, Object jupiter, Object saturn,
                    Object uranus, Object neptune) {
    int size = 120;        
    float step = 2.0f;    
    float scale = 50.0f;

    for (float x = -size; x <= size; x += step) {
        for (float z = -size; z <= size; z += step) {

            Vector3 p = { x, 0, z };
            float yWarp = 0.0f;

            yWarp += warpEffect(p, sun);
            yWarp += warpEffect(p, mercury);
            yWarp += warpEffect(p, venus);
            yWarp += warpEffect(p, earth);
            yWarp += warpEffect(p, mars);
            yWarp += warpEffect(p, jupiter);
            yWarp += warpEffect(p, saturn);
            yWarp += warpEffect(p, uranus);
            yWarp += warpEffect(p, neptune);
            

            p.y += yWarp * scale;

            Vector3 px = { x + step, 0, z };
            float yWarpX = warpEffect(px, sun) + warpEffect(px, mercury) + warpEffect(px, venus)
                            + warpEffect(px, earth) + warpEffect(px, mars) + warpEffect(px, jupiter)
                            + warpEffect(px, saturn) + warpEffect(px, uranus) + warpEffect(px, neptune);
            px.y += yWarpX * scale;

            Vector3 pz = { x, 0, z + step };
            float yWarpZ = warpEffect(pz, sun) + warpEffect(pz, mercury) + warpEffect(pz, venus)
                            + warpEffect(pz, earth) + warpEffect(pz, mars) + warpEffect(pz, jupiter)
                            + warpEffect(pz, saturn) + warpEffect(pz, uranus) + warpEffect(pz, neptune);
            pz.y += yWarpZ * scale;

            DrawLine3D(p, px, DARKGRAY);
            DrawLine3D(p, pz, DARKGRAY);
        }
    }
}


float warpEffect(Vector3 point, Object obj) {
    Vector3 diff = Vector3Subtract(obj.pos, point);
    float dist = Vector3Length(diff);
    if (dist < 1.5f) dist = 1.5f;
    return -obj.mass / (dist * dist * 2500.0f);

}

void updatePhysics(Object* planet){

    float dt = GetFrameTime();

    Vector3 dir = (Vector3){sun.pos.x - planet->pos.x ,sun.pos.y - planet->pos.y,sun.pos.z - planet->pos.z};
    float r = sqrt(dir.x * dir.x  + dir.y *dir.y + dir.z * dir.z);
    float Force = (G * sun.mass * planet->mass) / (r* r);
    Vector3 dirNorm = Vector3Normalize(dir);
    Vector3 F = (Vector3){ Force * dirNorm.x ,Force * dirNorm.y , Force * dirNorm.z};
    planet->acc = (Vector3){F.x / planet->mass , F.y / planet->mass , F.z / planet->mass};
    planet->vel = Vector3Add(planet->vel, Vector3Scale(planet->acc, dt));
    planet->pos = Vector3Add(planet->pos, Vector3Scale(planet->vel, dt));

    
}
