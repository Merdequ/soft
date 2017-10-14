#include <stdio.h>
#include <math.h>

#define IN        1
#define OUT       0
#define MAXLEN    25
#define MAXNWORD  23000

int  get_max( int array[], int N );

double  get_average( int array[], int N );

double  get_variance( int array[], int N );

void bubble_sort( int array[], int N );

/* もとのやつ
int main()
{
  int c, nl, nw, nc, state;
  int i, j;
  int word_initial, word_final, len;
  int word_length[MAXLEN];
  int numbers[MAXNWORD];

  for( i = 0 ; i < MAXLEN ; ++i ) {
    word_length[i] = 0;
  }
  for( i = 0 ; i < MAXNWORD ; ++i ) {
    numbers[i] = 0;
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

	numbers[nw] = (nl+1)*len;
	//	printf( "nw = %d, nl = %d, len = %d, numbers = %d\n", nw, nl, len, numbers[nw] );
	++nw;
      }
      state = OUT;
    }
    else if( state == OUT ) {
      state = IN;
      word_initial = nc;
    }

    if( c == '\n' ) {
      ++nl;
    }
  }

  printf( "#line = %d #word = %d #character = %d\n", nl, nw, nc );
  printf( "max = %d, avg = %.3f, var = %.3f\n", get_max( numbers, nw ),
	  get_average( numbers, nw ), get_variance( numbers, nw ) );

  return 0;
}
*/


int main()
{
  int c, nw;
  int i, j;
  int numbers[MAXNWORD];

  for( i = 0 ; i < MAXNWORD ; ++i ) {
    numbers[i] = 0;
  }
  nw = 0;

  printf("enter integers\n");
  
  while(scanf("%d",&numbers[nw]) != EOF) {
    ++nw;
  }

  printf( "\n%d numbers entered: max = %d, avg = %.3f, var = %.3f\n", nw,  get_max( numbers, nw ),
	  get_average( numbers, nw ), get_variance( numbers, nw ) );
  printf("\n sorting...\n");
  bubble_sort(numbers, nw );
  printf("\n completed\n");

  for(i = 0; i < nw; i++){
    printf("%d\n",numbers[i]);
  }

  return 0;
}

int  get_max( int array[], int N ){
  int max = array[0];
  for(int i = 1; i < N; i++){
    max = ((array[i] > max)? array[i] : max);
  }
  return max;
}

double  get_average( int array[], int N )
{
  double sum = 0;
  for(int i = 0; i < N; i++){
    sum += array[i];
  }
  return (sum / N);
}

double  get_variance( int array[], int N ){
  double temp = 0;
  double ave = get_average( array, N );
  for(int i = 0; i < N; i++){
    temp += pow(array[i] - ave,2);
  }
  return ( temp / N);
}

void bubble_sort( int array[], int N ){
  int temp;
  for( int i = 0; i < N - 1; i++){
    for( int j = 0; j < N - i - 1;j++){
      if(array[j] > array[j+1]){
	temp = array[j+1];
	array[j+1] = array[j];
	array[j] = temp;
      }
    }
  }
}
