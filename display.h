#include <math.h>
#include <stdlib.h>

#define SCREEN_WIDTH 500
#define SCREEN_HEIGHT 500

struct Vector {
    double pos[4];
};

struct Triangle {
    struct Vector pts[3];
    struct Vector normal;
};

struct Color {
    int red;
    int blue;
    int green;
    double transparency;
};

struct World {
    unsigned char **columns[SCREEN_WIDTH];
    float **zbuff[SCREEN_WIDTH];
    struct Light lights;
    struct Object world;
    struct Object viewplane;
};

struct Object {
    struct Object *children;
    struct Vector *edgelist;
    struct Vector center;
    struct Transform *T;
};
