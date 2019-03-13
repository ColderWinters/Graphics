struct Transformer Id_Matrix = calloc(1, sizeof(struct Transformer));

int i = 0;
while ( i < 4 ) {
  Id_Matrix.colums[i].pos[i] = 1;
}

double **Multiply( double *mat1, double *mat2, int depth ){
  int i = 0;
  while ( mat2[i] ) {
    int j = 0;
    while ( j < depth ) {
      int k = 0;
      double a;
      while ( k < depth ) {
        a += mat1[j].pos[k] * mat2[i].pos[j];
        k++;
      }
      mat2[i].pos[j] = a;
      j++;
    }
    i++;
  }
  return mat2;
}
