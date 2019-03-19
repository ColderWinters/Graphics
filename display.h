

#define SCREEN_WIDTH 500
#define SCREEN_HEIGHT 500

struct Vector {
    double pos[4];
};

struct Color {
    int red;
    int blue;
    int green;
    double transparency;
};

struct Screen {
  unsigned char *columns[SCREEN_WIDTH];
  struct Object *objects;
};

struct Object {
  struct Vector *edgelist;
  struct Transform *T;
};
