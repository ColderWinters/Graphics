
#DEFINE TYPE_POLYNOMIAL 0
#DEFINE TYPE_TRIG 1
#DEFINE TYPE_COMPOSITION 2
#DEFINE TYPE_ADD 3


struct Function {
  struct Function components[3];
};

struct SubFunction {
  double **coeff;
  double **extra;
  int type;
};
