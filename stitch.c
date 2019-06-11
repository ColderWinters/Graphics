#include "stitch.h"

double sqrd_dist( struct Vector v1, struct Vector v2 ) {
  double a = 0;
  for ( int i = 0; i < 3; i++ ) {
    a += ( v1.pos[i] - v2.pos[i] ) ** 2;
  }
  return a;
}

double dist( struct Vector v1, struct Vector v2 ) {
  return sqrt ( sqrd_dist( v1, v2 ) );
}

struct Vector *stitch_points ( struct Vector *inlist ) {
  struct Triangle *olist = malloc( 3 );//uhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhh\
  struct Triangle *tlist = malloc ( 4);/////uuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuh

  struct Vector *close_folks = calloc( CHECKS * sizeof( struct Vector * ) );

  int i = 0;
  while ( inlist[i] ) { //per point
    int j = 0;
    while ( inlist[j] ) {
      if ( i != j ) { //per point not me
        inlist[i].pos[4] = sqrd_dist( inlist[i], inlist[j] ); // me to point
        int k = 0;
        while ( close_folks[k] ) { /// check against close folks, populate
          int l = k;
          while ( inlist[i].pos[4] > close_folks[k].pos[4] ) {
            struct Vector *temp = close_folks[k];
            struct Vector *temp2;
            close_folks[k] = inlist[i];
            while ( close_folks[++l] ) {
              temp2 = *close_folks[l++];
              close_folks[l] = temp;
            }
          }
          k++;
        }
        ///find CHECKS closest neighborts
        /////Theres no reason you wouldnt want TO CHECK a triangle edge to one of your nearest folks
        //thats not true but they get culled out later
      }
    j++;
    }  //per point not me

    j = 0;
    while ( close_folks[j++] ) {
      ///make SOME triangles with me and my close_folks
            // ^-- define this: all of them; but leave them half open
    }

  i++;
  } // per point
  i = 0;
  while ( tlist[i++] ) {
    //also maybe cull triangles by anlgle between them ( closer norms are better)
    //recursion : base case is most positive z and then go by edges and normals?
    //yeah theres going to be a situation in which i can weigh well shaped triangles against well angled triangles
    //that could be a variance later also
  }

  i = 0;
  while ( olist[i++] ) {
    /////fix orientation
    // by checking nearest face then extending from there accross edges usign normals
    // do a queue thing, keep track of normals of triangles
  }

  ////////////current issues////////////////////
  /////how to ( if ) guarantee closure: maybe make an edge struct wih two triangles and an index for what edge is shared
  /////
  return olist;
}
