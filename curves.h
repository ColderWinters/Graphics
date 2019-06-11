#include "transformation.h"

#define TYPE_POLYNOMIAL 0
#define TYPE_TRIG 1
#define TYPE_COMPOSITION 2
#define TYPE_ADD 3
#define TYPE_SUBSTRACT 4
#define TYPE_DIVIDE 5
#define TYPE_MULTIPLY 6
#define TYPE_EXP 7
#define TYPE_LOG 8

struct SubFunction {
  double *coeffs;
  double *extras;
  int type;
};

struct Function {
  struct SubFunction components[3];
};
