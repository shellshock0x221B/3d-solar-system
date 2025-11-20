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

void updatePhysics(){

    float dt = GetFrameTime();

    //Mercury
    Vector3 dirM = (Vector3){sun.pos.x - mercury.pos.x ,sun.pos.y - mercury.pos.y,sun.pos.z - mercury.pos.z};
    float rM = sqrt(dirM.x * dirM.x  + dirM.y *dirM.y + dirM.z * dirM.z);
    float ForceM = (G * sun.mass * mercury.mass) / (rM * rM);
    Vector3 dirMNorm = Vector3Normalize(dirM);
    Vector3 FM = (Vector3){ ForceM * dirMNorm.x ,ForceM * dirMNorm.y , ForceM * dirMNorm.z};
    mercury.acc = (Vector3){FM.x / mercury.mass , FM.y / mercury.mass , FM.z / mercury.mass};
    mercury.vel = Vector3Add(mercury.vel, Vector3Scale(mercury.acc, dt));
    mercury.pos = Vector3Add(mercury.pos, Vector3Scale(mercury.vel, dt));

    //Venus
    Vector3 dirV = (Vector3){sun.pos.x - venus.pos.x ,sun.pos.y - venus.pos.y,sun.pos.z - venus.pos.z};
    float rV = sqrt(dirV.x * dirV.x  + dirV.y *dirV.y + dirV.z * dirV.z);
    float ForceV = (G * sun.mass * venus.mass) / (rV * rV);
    Vector3 dirVNorm = Vector3Normalize(dirV);
    Vector3 FV = (Vector3){ ForceV * dirVNorm.x ,ForceV * dirVNorm.y , ForceV * dirVNorm.z};
    venus.acc = (Vector3){FV.x / venus.mass , FV.y / venus.mass , FV.z / venus.mass};
    venus.vel = Vector3Add(venus.vel, Vector3Scale(venus.acc, dt));
    venus.pos = Vector3Add(venus.pos, Vector3Scale(venus.vel, dt));

    //Earth
    Vector3 dirE = (Vector3){sun.pos.x - earth.pos.x ,sun.pos.y - earth.pos.y,sun.pos.z - earth.pos.z};
    float rE = sqrt(dirE.x * dirE.x  + dirE.y *dirE.y + dirE.z * dirE.z);
    float EForce = (G * sun.mass * earth.mass) / (rE * rE);
    Vector3 dirENorm = Vector3Normalize(dirE);
    Vector3 FE = (Vector3){ EForce * dirENorm.x ,EForce * dirENorm.y , EForce * dirENorm.z};
    earth.acc = (Vector3){FE.x / earth.mass , FE.y / earth.mass , FE.z / earth.mass};
    earth.vel = Vector3Add(earth.vel, Vector3Scale(earth.acc, dt));
    earth.pos = Vector3Add(earth.pos, Vector3Scale(earth.vel, dt));

    //Mars
    Vector3 dirMa = (Vector3){sun.pos.x - mars.pos.x ,sun.pos.y - mars.pos.y,sun.pos.z - mars.pos.z};
    float rMa = sqrt(dirMa.x * dirMa.x  + dirMa.y *dirMa.y + dirMa.z * dirMa.z);
    float MaForce = (G * sun.mass * mars.mass) / (rMa * rMa);
    Vector3 dirMaNorm = Vector3Normalize(dirMa);
    Vector3 FMa = (Vector3){ MaForce * dirMaNorm.x ,MaForce * dirMaNorm.y , MaForce * dirMaNorm.z};
    mars.acc = (Vector3){FMa.x / mars.mass , FMa.y / mars.mass , FMa.z / mars.mass};
    mars.vel = Vector3Add(mars.vel, Vector3Scale(mars.acc, dt));
    mars.pos = Vector3Add(mars.pos, Vector3Scale(mars.vel, dt));

    //Jupiter
    Vector3 dirJ = (Vector3){sun.pos.x - jupiter.pos.x ,sun.pos.y - jupiter.pos.y,sun.pos.z - jupiter.pos.z};
    float rJ = sqrt(dirJ.x * dirJ.x  + dirJ.y *dirJ.y + dirJ.z * dirJ.z);
    float JForce = (G * sun.mass * jupiter.mass) / (rJ * rJ);
    Vector3 dirJNorm = Vector3Normalize(dirJ);
    Vector3 FJ = (Vector3){ JForce * dirJNorm.x ,JForce * dirJNorm.y , JForce * dirJNorm.z};
    jupiter.acc = (Vector3){FJ.x / jupiter.mass , FJ.y / jupiter.mass , FJ.z / jupiter.mass};
    jupiter.vel = Vector3Add(jupiter.vel, Vector3Scale(jupiter.acc, dt));
    jupiter.pos = Vector3Add(jupiter.pos, Vector3Scale(jupiter.vel, dt));

    //Saturn
    Vector3 dirS = (Vector3){sun.pos.x - saturn.pos.x ,sun.pos.y - saturn.pos.y,sun.pos.z - saturn.pos.z};
    float rS = sqrt(dirS.x * dirS.x  + dirS.y *dirS.y + dirS.z * dirS.z);
    float SForce = (G * sun.mass * saturn.mass) / (rS * rS);
    Vector3 dirSNorm = Vector3Normalize(dirS);
    Vector3 FS = (Vector3){ SForce * dirSNorm.x ,SForce * dirSNorm.y , SForce * dirSNorm.z};
    saturn.acc = (Vector3){FS.x / saturn.mass , FS.y / saturn.mass , FS.z / saturn.mass};
    saturn.vel = Vector3Add(saturn.vel, Vector3Scale(saturn.acc, dt));
    saturn.pos = Vector3Add(saturn.pos, Vector3Scale(saturn.vel, dt));

    //Uranus
    Vector3 dirU = (Vector3){sun.pos.x - uranus.pos.x ,sun.pos.y - uranus.pos.y,sun.pos.z - uranus.pos.z};
    float rU = sqrt(dirU.x * dirU.x  + dirU.y *dirU.y + dirU.z * dirU.z);
    float UForce = (G * sun.mass * uranus.mass) / (rU * rU);
    Vector3 dirUNorm = Vector3Normalize(dirU);
    Vector3 FU = (Vector3){ UForce * dirUNorm.x ,UForce * dirUNorm.y , UForce * dirUNorm.z};
    uranus.acc = (Vector3){FU.x / uranus.mass , FU.y / uranus.mass , FU.z / uranus.mass};
    uranus.vel = Vector3Add(uranus.vel, Vector3Scale(uranus.acc, dt));
    uranus.pos = Vector3Add(uranus.pos, Vector3Scale(uranus.vel, dt));

    //Neptune
    Vector3 dirN = (Vector3){sun.pos.x - neptune.pos.x ,sun.pos.y - neptune.pos.y,sun.pos.z - neptune.pos.z};
    float rN = sqrt(dirN.x * dirN.x  + dirN.y *dirN.y + dirN.z * dirN.z);
    float NForce = (G * sun.mass * neptune.mass) / (rN * rN);
    Vector3 dirNNorm = Vector3Normalize(dirN);
    Vector3 FN = (Vector3){ NForce * dirNNorm.x ,NForce * dirNNorm.y , NForce * dirNNorm.z};
    neptune.acc = (Vector3){FN.x / neptune.mass , FN.y / neptune.mass , FN.z / neptune.mass};
    neptune.vel = Vector3Add(neptune.vel, Vector3Scale(neptune.acc, dt));
    neptune.pos = Vector3Add(neptune.pos, Vector3Scale(neptune.vel, dt));

    
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
    if (dist < 1.2f) dist = 1.2f;
    return -obj.mass / (dist * dist * 2500.0f);

}
