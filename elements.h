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
extern Object mercury;
extern Object venus;
extern Object earth;
extern Object mars;
extern Object jupiter;
extern Object saturn;
extern Object uranus;
extern Object neptune;
extern Object moon;

void createObjects(void);
void drawObjects(void);
void updatePhysics(Object *planet);
void DrawWarpedGrid(Object sun, Object mercury, Object venus, Object earth,
                    Object mars, Object jupiter, Object saturn,
                    Object uranus, Object neptune);
float warpEffect(Vector3 point, Object obj);

#endif // ELEMENTS_H
