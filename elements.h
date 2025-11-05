#ifndef ELEMENTS_H
#define ELEMENTS_H

#include <raylib.h>

#define G 1.0f


typedef struct {
    Vector3 pos;
    Vector3 vel;
    float mass;
    Color col;
    float radius;
    Vector3 acc;

} Object;



extern Object sun;
extern Object planet;
extern Object earth;
extern Object planet1;


void createObjects(void);
void drawObjects(void);
void updatePhysics(void);
void DrawWarpedGrid(Object sun, Object planet, Object earth , Object planet1);
float warpEffect(Vector3 point, Object obj);


#endif // ELEMENTS_H
