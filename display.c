

struct *Screen makeScreen(){
  int i = 0;
  struct Screen this;
  while ( this[i] != NULL ) {
    char *col = calloc(sizeof(char), 500);
    this[i] = col;
    i++;
  }
  return this;
