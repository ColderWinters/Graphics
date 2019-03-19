

struct Screen makeScreen(){
  int i = 0;
  struct Screen this;
  while ( this[i] != NULL ) {
    this[i] = calloc( sizeof(*char), SCREEN_HEIGHT );
    for ( int j = 0; j <  SCREEN_HEIGHT; j++; ) {
      this[i][j] = calloc( 3, sizeof(char) )
    }
    i++;
  }
  return this;
}
