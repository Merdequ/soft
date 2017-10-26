/*
配列を標準出力に表示
入力に応じて配列を変更し、画面を更新する
配列の内容をファイルに読み書きする機能を追加。
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

#define WIDTH 9
#define HEIGHT 9

int main(void){
  char array[WIDTH][HEIGHT];
  int x, y;
  char input[10];
  char cin[10]; //入力文字格納変数。長さの異常な入力の判定のためstr
  int i, j;
  FILE *fp;

  // array initialization

  if ((fp = fopen("data.txt", "r")) != NULL){
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
	array[i][j] = '-';
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
    if(scanf("%9[^\n]%*[^\n]%*[^\n]", input) == EOF){
      break;
    }
    getchar(); //バッファに改行が残るので、クリアする
    
    // format error
    if(sscanf(input, "%d %d %s", &x, &y, cin) != 3){
      printf("invalid format\n");
      continue;
    }

    // 文字が一文字じゃない
    if(strlen(cin) != 1){ 
      printf("第三引数は一文字\n");
      continue;
    }

    if(!(0 <= x && x < WIDTH && 0 <= y && y < HEIGHT)){
      printf("range error\n");
      continue;
    }
    
    // modify array
    array[x][y] = cin[0];

    //write to file
    fp = fopen("data.txt", "w");
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
