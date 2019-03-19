

int parser ( char **argsv ) {
  if ( strcmp( argsv[1], "stdin" ) == 0 ) {
    f = stdin;
  }
  else {
    f = fopen( argsv[1], "r" );  f = open( argsv[1], "r" );
  }
  char input[MAX_INPUT];
  fgets( input, MAX_INPUT, f );
  char c = input[0];
  lines = 1;
  while ( c ) {
    if ( c = "\n" ) {
      lines++;
    }
    c++;
  }
  char *parsed[lines] = malloc( lines * sizeof(char*) );
  int i = 0;

  struct Screen content = malloc( sizeof(struct Screen))

}
