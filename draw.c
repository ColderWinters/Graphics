

int draw( struct Screen screen, char *name ) {

}

void line( struct Vector p1, struct Vector p2, struct Color colors ) {

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

void draw_line( struct Vector V1, struct Vector V2, struct Color color ) {
	if V1.pos[0] > V2.pos[0] {
		V1.pos[0] = V1.pos[0] ^ V2.pos[0];
		V2.pos[0] = V1.pos[0] ^ V2.pos[0];
		V1.pos[0] = V1.pos[0] ^ V2.pos[0];
		//found this cool algorithm for switching variables in place
		V1.pos[1] = V1.pos[1] ^ V2.pos[1];
		V2.pos[1] = V1.pos[1] ^ V2.pos[1];
		V1.pos[1] = V1.pos[1] ^ V2.pos[1];
	}

*/
