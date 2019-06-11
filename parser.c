#include "parser.h"

int parser( char **argsv ) {
  char f;
  if ( strcmp( argsv[1], "stdin" ) == 0 ) {
    f = STDIN;
  }
  else {
    f = open( argsv[1], O_RDONLY );
  }
  char input[MAX_INPUT];
  read( f, input, MAX_INPUT );
  char c = input[0];
  int lines = 1;
  while ( c ) {
    if ( c = *"\n" ) {
      lines++;
    }
    c++;
  }
  char **parsed = malloc( lines * sizeof(long) );
  int i = 0;

  struct Screen content = makeScreen();

/*
The commands are as follows:
    sphere: add a sphere to the edge matrix -
            takes 4 arguemnts (cx, cy, cz, r)
    torus: add a torus to the edge matrix -
           takes 5 arguemnts (cx, cy, cz, r1, r2)
    box: add a rectangular prism to the edge matrix -
         takes 6 arguemnts (x, y, z, width, height, depth)
    clear: clears the edge matrix
    circle: add a circle to the edge matrix -
            takes 4 arguments (cx, cy, cz, r)
    hermite: add a hermite curve to the edge matrix -
             takes 8 arguments (x0, y0, x1, y1, rx0, ry0, rx1, ry1)
    bezier: add a bezier curve to the edge matrix -
            takes 8 arguments (x0, y0, x1, y1, x2, y2, x3, y3)
    line: add a line to the edge matrix -
          takes 6 arguemnts (x0, y0, z0, x1, y1, z1)
    ident: set the transform matrix to the identity matrix -
    scale: create a scale matrix,
           then multiply the transform matrix by the scale matrix -
           takes 3 arguments (sx, sy, sz)
    move: create a translation matrix,
          then multiply the transform matrix by the translation matrix -
          takes 3 arguments (tx, ty, tz)
    rotate: create a rotation matrix,
            then multiply the transform matrix by the rotation matrix -
            takes 2 arguments (axis, theta) axis should be x y or z
    apply: apply the current transformation matrix to the edge matrix
    display: clear the screen, then
             draw the lines of the edge matrix to the screen
             display the screen
    save: clear the screen, then
          draw the lines of the edge matrix to the screen
          save the screen to a file -
          takes 1 argument (file name)
    quit: end parsing
*/

  while ( fgets(line, sizeof(line), f) != NULL ) {
    line[strlen(line)-1]='\0';
    //printf(":%s:\n",line);

    struct Screen frame = makeScreen();
    struct Object **refs;
    char **refnames;
    double xvals[4];
    double yvals[4];
    double zvals[4];
    struct matrix *tmp;
    double r;
    double theta;
    struct Vector axis;
    int step = 100;

    if ( strncmp( line, "line", strlen(line) ) == 0 ) {
      fgets(line, sizeof(line), f);
      sscanf(line, "%lf %lf %lf %lf %lf %lf",
                    xvals, yvals, zvals,
                    xvals+1, yvals+1, zvals+1);
      circle( edges, xvals[0], yvals[0], zvals[0], r, step);
    }














    else if ( strncmp(line, "hermite", strlen(line)) == 0 ||
              strncmp(line, "bezier", strlen(line)) == 0 ) {
      if (strncmp(line, "hermite", strlen(line)) == 0 )
        type = HERMITE;
      else
        type = BEZIER;

      fgets(line, sizeof(line), f);

      sscanf(line, "%lf %lf %lf %lf %lf %lf %lf %lf",
             xvals, yvals, xvals+1, yvals+1,
             xvals+2, yvals+2, xvals+3, yvals+3);

      add_curve( edges, xvals[0], yvals[0], xvals[1], yvals[1],
                 xvals[2], yvals[2], xvals[3], yvals[3], step, type);
        }
        else if ( strncmp(line, "line", strlen(line)) == 0 ) {
          fgets(line, sizeof(line), f);

          sscanf(line, "%lf %lf %lf %lf %lf %lf",
                       xvals, yvals, zvals,
                       xvals+1, yvals+1, zvals+1);
          add_edge(edges, xvals[0], yvals[0], zvals[0],
                   xvals[1], yvals[1], zvals[1]);
        }

        else if ( strncmp(line, "scale", strlen(line)) == 0 ) {
          fgets(line, sizeof(line), f);
          sscanf(line, "%lf %lf %lf",
                        xvals, yvals, zvals);
          tmp = make_scale( xvals[0], yvals[0], zvals[0]);
          matrix_mult(tmp, transform);
    }

    else if ( strncmp(line, "move", strlen(line)) == 0 ) {
      fgets(line, sizeof(line), f);
      sscanf(line, "%lf %lf %lf",
             xvals, yvals, zvals);
      tmp = make_translate( xvals[0], yvals[0], zvals[0]);
      matrix_mult(tmp, transform);
    }

    else if ( strncmp(line, "rotate", strlen(line)) == 0 ) {
      fgets(line, sizeof(line), f);
      sscanf(line, "%c %lf",
                   &axis, &theta);
      theta = theta * (M_PI / 180);
      if ( axis == 'x' )
        tmp = make_rotX( theta );
      else if ( axis == 'y' )
        tmp = make_rotY( theta );
      else
        tmp = make_rotZ( theta );
      matrix_mult(tmp, transform);
    }

    else if ( strncmp(line, "ident", strlen(line)) == 0 ) {
      ident(transform);
    }

    else if ( strncmp(line, "apply", strlen(line)) == 0 ) {
      matrix_mult(transform, edges);
    }

    else if ( strncmp(line, "display", strlen(line)) == 0 ) {
      clear_screen(s);
      draw_lines(edges, s, c);
      display( s );
    }

    else if ( strncmp(line, "save", strlen(line)) == 0 ) {
      fgets(line, sizeof(line), f);
      *strchr(line, '\n') = 0;
      clear_screen(s);
      draw_lines(edges, s, c);
      save_extension(s, line);
    }
  }
}
