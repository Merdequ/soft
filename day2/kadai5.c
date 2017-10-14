#include <stdio.h>
#include <math.h>

#define IN        1
#define OUT       0
#define MAXLEN    25
#define MAXNWORD  100

int is_kaibun( char array[], int N );

int main()
{
  int c, nl, nw, nc, state;
  int i, j;
  int word_initial, word_final, len;
  int word_length[MAXLEN];
  int length[MAXNWORD];
  char words[MAXNWORD][MAXLEN];

  for( i = 0 ; i < MAXLEN ; ++i ) {
    word_length[i] = 0;
  }
  for( i = 0 ; i < MAXNWORD ; ++i ) {
    for(j = 0; j < MAXLEN; j++)
      words[i][j] = 0;
  }

  state = OUT;
  nl = nw = nc = 0;
  while( ( c = getchar() ) != EOF ) {
    ++nc;

    if( c == ' ' || c == '\n' || c == '\t' ) {
      if( state == IN ) {
	word_final = nc;
	len = word_final - word_initial;
	++word_length[len];
	length[nw] = len;
	//	printf( "nw = %d, nl = %d, len = %d, numbers = %d\n", nw, nl, len, numbers[nw] );
	++nw;
      }
      state = OUT;
    }
    else{
      if( state == OUT ) {
	state = IN;
	word_initial = nc;
      }
      words[nw][nc - word_initial] = (char)c;
    }

    if( c == '\n' ) {
      ++nl;
    }
  }

  printf( "#line = %d #word = %d #character = %d\n", nl, nw, nc );

  for(i = 0; i < nw; i++){
    printf("%s ",words[i]);
    printf("%s\n",((is_kaibun(words[i],length[i])? "is Kaibun" : "is not Kaibun")));
  }

  return 0;
}

int is_kaibun( char array[], int N ){
  for(int i=0; i < N/2; i++){
    if(array[i] != array[ N - i - 1]){
      return 0;
    }
  }
  return 1;
}
