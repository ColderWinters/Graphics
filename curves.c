#include "curves.h"

int factorial ( int n ) {
  int a = 1;
  while ( n > 0 ) {
    a = a * n;
    n--;
  }
  return a;
}

int choose ( int n, int k ) {
  return ( factorial( n ) / (factorial( k ) * factorial( n - k ) ) );
}

struct Function *Bezzy( struct Screen jeff, struct Vector *points ) {
  struct Vector *this;
  int len = 1;
  while ( this ) {
    this = &points[len];
    len += 1;
  }
  int f = 0;
  struct Function *out = calloc( 1, sizeof(struct Function) );
  while ( f < 3 ) {
    int degree = 0 ;
    struct SubFunction *current = malloc( sizeof( struct SubFunction ));
    current = & out->components[f];
    current->type = TYPE_POLYNOMIAL;
    current->coeffs = malloc( len * sizeof(double) );
    current->extras = malloc( len * sizeof(double) );
    double *carry[len];
    int i = 0;
    while ( carry[i] ) {
      i += 1;
      carry[i] = malloc( sizeof(double) );
      int itt = 0;
      while ( itt < ( i + 1 ) ) {
        carry[i][itt] = choose( itt, i ) * pow( (-1), itt );
        itt++;
      }
    }
    while ( degree < ( len + 1 ) ) {
      double a = 0;
      i = 0;
      while ( i < ( degree + 1 )  ) {
        a += carry[i][degree];
        i++;
      }
      current->coeffs[degree] = choose( degree, len )
                              * choose( (len - degree) , len )
                              * points[degree].pos[f]
                              * a;
      current->extras[degree] = trunc(degree);
    }
  }
  return out;
}
/*
struct Function spline( struct Vector *points, struct Vector *diffs ) {
  len = cols( points );
  double **solverM = malloc( ( len * 2 ) + 1 );
  int i = -1;
  while( points[i++] ) {
    double *colmn = malloc( 2 * len );
    while( j ) {
      pwrterm = ( ( 1 / (len - 1) ) * j )
      solverM[2*i-1][2*j-1] =
      solverM[2i][2j] =
    }
  }
}
*/
