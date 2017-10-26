/*
配列を標準出力に表示
1秒に一回表示書き換え
 */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#define SIZE 9

int main(void){
  char array[SIZE][SIZE];
  int i, j, t;
  // array initialization
  for(i = 0; i < SIZE; i++){
    for(j = 0; j < SIZE; j++){
      array[i][j] = '-';
    }
  }

  // main loop
  for(t = 0; t <= SIZE; t++){
    //display
    system("clear");
    for(i = 0; i < SIZE; i++){
      for(j = 0; j < SIZE; j++){
	printf("%c ", array[i][j]);
      }
      printf("\n");
    }
    
    // modify array
    if(t < SIZE){
      array[t][t] = '*';
    }
    //
    sleep(1);
  }
  return 0;
}
