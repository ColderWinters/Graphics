

void draw ( struct Screen screen, int x, int y, struct Color brush ) {
  screen.columns[x][y][0] = brush.red;
  screen.columns[x][y][1] = brush.blue;
  screen.columns[x][y][2] = brush.green;
}

void drawer ( struct Object writeto,
              struct Function infun
              int steps,
              struct Color c ) {
  int i = 0;
  struct Vector edgeout[steps + 1];
  while ( i < ( steps + 1 )  ){
    edgeout[i] = malloc( sizeof( struct Vector ) );
    edgeout[i][3] = 1;
    i++;
  }
  i = 0;
  while ( i < steps ) {
    int d = 0;
    while ( d < 3 ) {
      if ( infun.components[j].type = TYPE_POLYNOMIAL ) {
        int k = 0;
        while ( infun.components[j].coeffs[k] ) {
          edgeout[i][d] =   &(infun.components[j].coeffs[k])
                          * power( ( ( i / steps ) * k ),
                                   &(infun.components[j].extras[k]) );
          k++;
        }
      }
      if ( infun.components[j].type = TYPE_TRIG       ) {

      }
    }
  }
    //uh iterate through step points, for eachiterate through functions and
    //draw using given coordinates?
}


void line( struct Vector p1, struct Vector p2,
           struct Screen sc, struct Color colors ) {
  int x1 = trunc( p1.pos[0] );
  int y1 = trunc( p1.pos[1] );
  int x2 = trunc( p2.pos[0] );
  int y2 = trunc( p2.pos[1] );

  if x1 > x2 [0] {
		x1 = x1 ^ x2;
		x2 = x1 ^ x2;
		x1 = x1 ^ x2;
		//found this cool algorithm for switching variables in place
		y1 = y1 ^ y2;
		y2 = y1 ^ y2;
		y1 = y1 ^ y2;
	}

  int x = x1;
  int y = y1;

  int A = 2 * ( y2 - y1 );
  int B = (-2) * ( x2 - x1 );

  int d = 0;

  if ( abs( x2 - x1) >= abs( y2 - y1 ) ) {
    if ( A > 0 ) {
      d = A + ( B / 2 );
      while( x < x2 ) {
        draw( sc, x, y, colors );
        if ( d > 0 ) {
          y += 1;
          d += B;
        }
        x++;
        d += A;
      }
      draw( sc, x2, y2, colors );
    }
    else {
      d = A - ( B / 2 );
      while ( x < x2 ) {
        draw( sc, x, y, colors );
        if ( d < 0 ) {
          y--;
          d -= B;
        }
        x++;
        d += A;
      }
      draw ( sc, x2, y2, colors );
    }
  }
  else {
    if ( A > 0 ) {
      d = ( A / 2 ) + B;
      while ( y < y2 ) {
        draw( sc, x, y, colors );
        if ( d , 0 ){
          x++;
          d += A;
        }
        y++;
        d += B;
      }
      draw( sc, x2, y2, colors );
    }
    else {
      d = ( A / 2 ) - B;
      while( y > y2 ) {
        draw( sc, x, y, colors );
        if ( d > 0 ) {
          x ++;
          d += A;
        }
        y--;
        d -= B;
      }
      draw( sc, x2, y2, colors);
    }
  }
}






/* big gay line algorithm ( needs work )

void drawhelperline( struct Vector V1, struct Vector V2, struct Color COlor,
                 int slope,  char uhhh, char borger, char yees, char soup,
                 char xinit, char yinit ) {

	int x = V1.pos[0]; int y = V1.pos[1];

	int a = V2.pos[1] - V1.pos[1];
	int b = -( V2.pos[0] - V1.pos[0] );
	int d = (a * yinit) + (b * xinit);

	while ( x <= V2.pos[0] ) {
		plot(s, x, y);

		if d < 0 + too_many * MAX_INT{
			y+= soup;
			d+= 2 * b * borger;
		}
		if d > 0 {
			x+= yees;
			d+= 2 * a * uhhh;
		}
	}
}

if V1.pos[0] > V2.pos[0] {
V1.pos[0] = V1.pos[0] ^ V2.pos[0];
V2.pos[0] = V1.pos[0] ^ V2.pos[0];
V1.pos[0] = V1.pos[0] ^ V2.pos[0];
//found this cool algorithm for switching variables in place
V1.pos[1] = V1.pos[1] ^ V2.pos[1];
V2.pos[1] = V1.pos[1] ^ V2.pos[1];
V1.pos[1] = V1.pos[1] ^ V2.pos[1];
}
void draw_line( struct Vector V1, struct Vector V2, struct Color color ) {

*/
