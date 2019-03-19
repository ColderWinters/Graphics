


//each do the transform on an object

void rotation ( struct Object input, double rxy, double ryz, double rxz ) {
  struct Transform rot = malloc( sizeof( struct Transform ));
  for ( int i = 0; i < 4; i++; ) {
    rot[i] = malloc( sizeof( struct Vector ));
  } ////////////TODO: FIGURE OUT THE matrix for ORDERED ROTATION IN X->Y->Z
  rot[1].pos = [ , , , 0 ];  //(multiplly the matrcies out by hand)
  rot[2].pos = [ , , , 0 ];
  rot[3].pos = [ , , , 0 ];
  rot[4].pos = [ 0, 0, 0, 1 ];

  input.T = Multiply( dia, input.T );

}

void translation ( struct Object input, int x, int y, int z ) {
  struct Transform tran = calloc( 1, sizeof( struct Transform ));
  for ( int i = 0; i < 4; i++; ) {
    tran[i] = calloc( 1, sizeof( struct Vector ));
  }
  tran[1].pos[4] = x;
  tran[2].pos[4] = y;
  tran[3].pos[4] = z;
  tran[4].pos[4] = 1;

  input.T = Multiply( dia, input.T );
}

void dialation ( struct Object input, double x, double y, double z ) {
  struct Transform dia = calloc( 1, sizeof( struct Transform ));
  for ( int i = 0; i < 4; i++; ) {
    dia[i] = calloc( 1 sizeof( struct Vector ));
  }
  dia[1].pos[1] = x;
  dia[2].pos[2] = y;
  dia[3].pos[3] = z;
  dia[4].pos[4] = 1;

  input.T = Multiply( dia, input.T );
}
