#import <math.h>


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

struct Function Bezzy( struct Screen jeff, struct Vector *points ) {
  struct Vector *this;
  int len = 1;
  while ( this ) {
    this = points[len];
    len += 1;
  }
  int f = 0;
  struct Function out = calloc( 1, sizeof(struct Function) );
  while ( f < 3 ) {
    int degree = 0 ;
    current = out[f];
    current.type = TYPE_POLYNOMIAL;
    current.coeff = malloc( len * sizeof(double) );
    current.extra = malloc( len * sizeof(double) );
    double *carry[len];
    int i = 0;
    double *epic = carry[i];
    while ( epic ) {
      i += 1;
      epic[i] = malloc( i, sizeof(double) );
      itt = 0;
      while ( itt < ( i + 1 ) ) {
        epic[i][itt] = choose( itt, i ) * power( (-1), itt );
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
      current.coeff[degree] = choose( degree, len )
                              * choose( (len - degree) , len )
                              * points[degree].pos[f]
                              * a;
      current.extra[degree] = degree;
    }
  }
  return out;
}

struct Function spline( struct Vector *points, struct Vector *diffs ) {

}
