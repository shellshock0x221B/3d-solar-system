#include "elements.h"
#include <raylib.h>
#include <math.h>
#include "raymath.h"




    Object earth;
    Object planet;
    Object planet1;
    Object sun;
    Object moon;

    void createObjects(){
        //Sun 
        sun.pos = (Vector3){0.0f , 2.0f , 0.0f};
        sun.vel = (Vector3){700 , 400 , 0.0f};
        sun.radius = 2;
        sun.col = YELLOW;
        sun.mass = 1000;
        //other plant 
        planet.mass = 100;
        planet.pos = (Vector3){7.0f, 2.0f, 0.0f};
        planet.vel = (Vector3){0.0f, 0.0f, 9.0f};
        planet.radius = 0.5;
        planet.col = RED;
        //earth
        earth.mass = 250;
        earth.pos = (Vector3){10.0f, 2.0f, 0.0f};
        earth.vel = (Vector3){0.0f, 0.0f, 10.0f};
        earth.radius = 1;
        earth.col = BLUE;
        //planet1
        planet1.mass = 300;
        planet1.pos = (Vector3){18.0f, 2.0f, 0.0f};
        planet1.vel = (Vector3){2.0f, 0.0f, 8.0f};
        planet1.radius = 1.5;
        planet1.col = BROWN;
        //Moon
        moon.mass = 60;
        moon.pos = (Vector3) {21.0f, 4.0f, 0.0f};
        moon.vel = (Vector3){0.0f, 0.0f, 16.0f};
        moon.radius = 0.3f;
        moon.col = WHITE;


    }

    void drawObjects(){
        DrawSphere(sun.pos , sun.radius, sun.col);
        DrawSphere(planet.pos, planet.radius, planet.col);
        DrawSphere(earth.pos, earth.radius,earth.col);
        DrawSphere(planet1.pos, planet1.radius, planet1.col);
        DrawSphere(moon.pos, moon.radius, moon.col);
        

    }

    void updatePhysics(){

        Vector3 dir = (Vector3){sun.pos.x - planet.pos.x ,sun.pos.y - planet.pos.y,sun.pos.z - planet.pos.z};
        float r = sqrt(dir.x * dir.x  + dir.y *dir.y + dir.z * dir.z);
        float Force = (G * sun.mass * planet.mass) / (r * r);
        Vector3 dirNorm = Vector3Normalize(dir);
        Vector3 F = (Vector3){ Force * dirNorm.x ,Force * dirNorm.y , Force * dirNorm.z};
        planet.acc = (Vector3){F.x / planet.mass , F.y / planet.mass , F.z / planet.mass};
        //sun.acc = (Vector3){F.x / sun.mass , F.y / sun.mass , F.z / sun.mass};
        
        //place Update
        float dt = GetFrameTime(); 
        planet.vel.x += planet.acc.x * dt;
        planet.vel.y += planet.acc.y * dt;
        planet.vel.z += dt *  planet.acc.z ;

        


        planet.pos.x += planet.vel.x * dt;
        planet.pos.y += planet.vel.y * dt;
        planet.pos.z += planet.vel.z * dt;

        Vector3 dirE = (Vector3){sun.pos.x - earth.pos.x ,sun.pos.y - earth.pos.y,sun.pos.z - earth.pos.z};
        float rE = sqrt(dirE.x * dirE.x  + dirE.y *dirE.y + dirE.z * dirE.z);
        float EForce = (G * sun.mass * earth.mass) / (rE * rE);
        Vector3 dirENorm = Vector3Normalize(dirE);
        Vector3 FE = (Vector3){ EForce * dirENorm.x ,EForce * dirENorm.y , EForce * dirENorm.z};
        earth.acc = (Vector3){FE.x / earth.mass , FE.y / earth.mass , FE.z / earth.mass};
        //sun.acc = (Vector3){F.x / sun.mass , F.y / sun.mass , F.z / sun.mass};
        
        //place Update
        
        earth.vel.x += earth.acc.x * dt;
        earth.vel.y += earth.acc.y * dt;
        earth.vel.z += dt *  earth.acc.z ;

        


        earth.pos.x += earth.vel.x * dt;
        earth.pos.y += earth.vel.y * dt;
        earth.pos.z += earth.vel.z * dt;


        Vector3 dirP1 = (Vector3){sun.pos.x - planet1.pos.x ,sun.pos.y - planet1.pos.y,sun.pos.z - planet1.pos.z};
        float rP1 = sqrt(dirP1.x * dirP1.x  + dirP1.y *dirP1.y + dirP1.z * dirP1.z);
        float P1Force = (G * sun.mass * planet1.mass) / (rP1 * rP1);
        Vector3 dirP1Norm = Vector3Normalize(dirP1);
        Vector3 FP1 = (Vector3){ P1Force * dirP1Norm.x ,P1Force * dirP1Norm.y , P1Force * dirP1Norm.z};
        planet1.acc = (Vector3){FP1.x / planet1.mass , FP1.y / planet1.mass , FP1.z / planet1.mass};
        //sun.acc = (Vector3){F.x / sun.mass , F.y / sun.mass , F.z / sun.mass};
        
        //place Update
        
        planet1.vel.x += planet1.acc.x * dt;
        planet1.vel.y += planet1.acc.y * dt;
        planet1.vel.z += dt *  planet1.acc.z ;

        


        planet1.pos.x += planet1.vel.x * dt;
        planet1.pos.y += planet1.vel.y * dt;
        planet1.pos.z += planet1.vel.z * dt;

        Vector3 dirM = (Vector3){planet1.pos.x - moon.pos.x ,planet1.pos.y - moon.pos.y,planet1.pos.z - moon.pos.z};
        float rM = sqrt(dirM.x * dirM.x  + dirM.y * dirM.y + dirM.z * dirM.z);
        float MForce = (G * planet1.mass * moon.mass) / (rM * rM);
        Vector3 dirMNorm = Vector3Normalize(dirM);
        Vector3 fM = (Vector3){ MForce * dirMNorm.x ,MForce * dirMNorm.y , MForce * dirMNorm.z};
        
        //sun.acc = (Vector3){F.x / sun.mass , F.y / sun.mass , F.z / sun.mass};
        Vector3 dirMSun = Vector3Subtract(sun.pos, moon.pos);
        float rMSun = Vector3Length(dirMSun);
        float MSunForce = (G * sun.mass * moon.mass) / (rMSun * rMSun);
        Vector3 dirMSunNorm = Vector3Normalize(dirMSun);
        Vector3 fMSun = Vector3Scale(dirMSunNorm, MSunForce);

    moon.acc = Vector3Scale(Vector3Add(fM, fMSun), 1.0f / moon.mass);
        //place Update
        
        moon.vel = Vector3Add(moon.vel, Vector3Scale(moon.acc, dt));
moon.pos = Vector3Add(moon.pos, Vector3Scale(moon.vel, dt));

        


    }

    void DrawWarpedGrid(Object sun, Object planet, Object earth , Object planet1) {
    int size = 35;        
    float step = 1.0f;    
    float scale = 100.0f;

    for (float x = -size; x <= size; x += step) {
        for (float z = -size; z <= size; z += step) {

            Vector3 p = { x, 0, z };
            float yWarp = 0.0f;

        
            yWarp += warpEffect(p, sun);
            yWarp += warpEffect(p, planet);
            yWarp += warpEffect(p, earth);
            yWarp += warpEffect(p, planet1);


            p.y += yWarp * scale;


            Vector3 px = { x + step, 0, z };
            float yWarpX = warpEffect(px, sun) + warpEffect(px, planet) + warpEffect(px, earth) + warpEffect(px, planet1);
            px.y += yWarpX * scale;

            Vector3 pz = { x, 0, z + step };
            float yWarpZ = warpEffect(pz, sun) + warpEffect(pz, planet) + warpEffect(pz, earth)+ warpEffect(pz, planet1);
            pz.y += yWarpZ * scale;

            DrawLine3D(p, px, DARKGRAY);
            DrawLine3D(p, pz, DARKGRAY);
        }
    }
}


float warpEffect(Vector3 point, Object obj) {
    Vector3 diff = Vector3Subtract(obj.pos, point);
    float dist = Vector3Length(diff);
    if (dist < 0.2f) dist = 0.2f;
    return -obj.mass / (dist * dist * 2000.0f);
}

