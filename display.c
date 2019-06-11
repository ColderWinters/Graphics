#include "display.h"


struct Screen makeScreen() {
  int i = 0;
  struct Screen this;
  while ( this.columns[i] != NULL ) {
    this.columns[i] = calloc( sizeof(char*), SCREEN_HEIGHT );
    for ( int j = 0; j <  SCREEN_HEIGHT; j++ ) {
      this.columns[i][j] = calloc( 3, sizeof(char) );
    }
    i++;
  }
  return this;
}
