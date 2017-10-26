/*
LIFE GAME
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

#define WIDTH 30
#define HEIGHT 30
#define LIVE 'O'
#define DEAD '-'

int main(void){
  char array[WIDTH][HEIGHT];
  int x, y;
  char input[10];
  int i, j;
  FILE *fp;

  // array initialization

  if ((fp = fopen("savedata.txt", "r")) != NULL){
    // read from file
    for(i = 0; i < WIDTH; i++){
      for(j = 0; j < HEIGHT; j++){
	array[i][j] = getc(fp);
      }
    }
    fclose(fp);
    printf("read from file successfully\n\n");
  }
  else{
    // first initialization 
    for(i = 0; i < WIDTH; i++){
      for(j = 0; j < HEIGHT; j++){
	array[i][j] = DEAD;
      }
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
  while(1){
    //異常入力で無限ループに陥らないようにしている
    //一度文字列として読み込んで、sscanf

    // input process
    if(scanf("%9[^\n]%*[^\n]", input) == EOF){
      break;
    }
    getchar(); //バッファに改行が残るので、クリアする
    
    // format error
    if(sscanf(input, "%d %d", &x, &y) != 2){
      printf("invalid format\n");
      continue;
    }

    if(!(0 <= x && x < WIDTH && 0 <= y && y < HEIGHT)){
      printf("range error\n");
      continue;
    }
    
    // modify array
    array[x][y] = (array[x][y] == LIVE)? DEAD: LIVE;

    //write to file
    fp = fopen("savedata.txt", "w");
    for(i = 0; i < WIDTH; i++){
      for(j = 0; j < HEIGHT; j++){
	fputc(array[i][j], fp);
      }
    }
    fclose(fp);
    
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
