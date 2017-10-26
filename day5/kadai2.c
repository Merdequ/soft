/*
配列を標準出力に表示
入力に応じて配列を変更し、画面を更新する
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#define WIDTH 9
#define HEIGHT 9

int main(void){
  char array[WIDTH][HEIGHT];
  int x, y;
  char input;
  int i, j;
  // array initialization
  for(i = 0; i < WIDTH; i++){
    for(j = 0; j < HEIGHT; j++){
      array[i][j] = '-';
    }
  }
  //display
  system("clear");
  for(i = 0; i < WIDTH; i++){
    for(j = 0; j < HEIGHT; j++){
      printf("%c ", array[i][j]);
    }
    printf("\n");
  }


  
  // main loop
  while(scanf("%d %d %c", &x, &y, &input) != EOF){    
    if(!(0 <= x && x < WIDTH && 0 <= y && y < HEIGHT)){
      printf("range error\n");
      continue;
    }  
    // modify array
    array[x][y] = input;
    
    //display
    system("clear");
    for(i = 0; i < WIDTH; i++){
      for(j = 0; j < HEIGHT; j++){
	printf("%c ", array[i][j]);
      }
      printf("\n");
    }
  }
  printf("end successfully\n");
  return 0;
}
