#include "matrix.h"
#include <math.h>

/*
int i = 0;
struct Transformer Id_Matrix = malloc( 1, sizeof( struct Transformer ));
while ( i < 4 ) {
  Id_matrix.columns[i] = calloc( 1, sizeof( struct Vector )));
  Id_Matrix.columns[i].pos[i] = 1;
}
*/

double **Multiply( double **mat1, double **mat2, int depth ){
  int i = 0;
  while ( mat2[i] ) {
    int j = 0;
    while ( j < depth ) {
      int k = 0;
      double a;
      while ( k < depth ) {
        a += mat1[j][k] * mat2[i][j];
        k++;
      }
      mat2[i][j] = a;
      j++;
    }
    i++;
  }
  return mat2;
}

int cols( double **input ) {
  int i = 0;
  while ( input[i++] );
  return i;
}

void rsheer( double **input, int row, int target, double c ) {
  for ( int i = 0; input[i]; i++ ) {
    input[i][row] += ( input[i][target] * c );
  }
}

void rswap( double **input, int row1, int row2 ) {
  for ( int i = 0; input[i]; i++ ) {
		double temp = input[i][row1];
		input[i][row2] = input[i][row1]; //found a use for it
		input[i][row1] = temp;           //didnt go about using it because im (not) a fool
  }
}

void rscale( double **input, int row, double c ) {
  for ( int i = 0; input[i]; i++ ) {
    input[i][row] = ( input[i][row] * c );
  }
}

//returns the reduced row echelon form of input
double **gauss_jordan( double **input, int depth ) {
  int i = 0;
  int len = cols( input );
  while ( i < len ) {
    for ( int j = 0; j < depth; j++ ) {
      int k = 0;
      while ( !input[i][j] && ( k < depth ) ) { //check for leading 0s
        rswap( input, j, k );
        k++;
      }
      if ( k < depth ) { //do the thing for all rows below this
        rscale( input, j, ( 1 / input[i][j] ) );
        for( int l = 0; l < depth; l++ ) {
          if ( l != j ) {
            rsheer( input, i, l, ( 1 / ( input[i][l] ) ) );
          }
        }
      }
    }
  }
}


double **Invert( double **input ) {
  int len = cols( input );
  input = realloc( input, ( ( len * 2 ) * sizeof(double) ) );
  for ( int I = 0; I < len; I++ ) {
    input[ len + I ] = calloc( len, sizeof(double));
    input[ len + I ][I] = 1;
  }
  input = gauss_jordan( input, len );
  for ( int i = 0; i < len; i++ ) {
    free( input[i] ); //free the right side identity matrix that you should have
    input[i] = input[ len + i ];
  }
  return realloc( input, ( len * sizeof(double) ) );
}
