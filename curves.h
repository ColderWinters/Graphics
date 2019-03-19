
#DEFINE TYPE_POLYNOMIAL 0
#DEFINE TYPE_TRIG 1
#DEFINE TYPE_COMPOSITION 2
#DEFINE TYPE_ADD 3
#DEFINE TYPE_DIVIDE 4
#DEFINE TYPE_EXP 5


struct Function {
  struct Function components[3];
};

struct SubFunction {
  double **coeff;
  double **extra;
  int type;
};
