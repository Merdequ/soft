/*
LIFE GAME
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#define WIDTH 50
#define HEIGHT 30
#define LIVE 'O'
#define DEAD '-'
#define CLOCK 200 //ms

void display(const char array[HEIGHT][WIDTH]);
void modify(char array[][WIDTH]);
void edit(char array[HEIGHT][WIDTH]);

int main(void){
  char array[HEIGHT][WIDTH];
  int x, y;
  int t = 0;
  char input[10];
  int i, j;
  FILE *fp;

  // array initialization

  if ((fp = fopen("savedata.txt", "r")) != NULL){
    // read from file
    for(i = 0; i < HEIGHT; i++){
      for(j = 0; j < WIDTH; j++){
	array[i][j] = getc(fp);
      }
    }
    fclose(fp);
    printf("read from file successfully\n\n");
  }
  else{
    // first initialization 
    for(i = 0; i < HEIGHT; i++){
      for(j = 0; j < WIDTH; j++){
	array[i][j] = DEAD;
      }
    }
  }
  
  display(array);
  printf("\n'run' / 'step' / 'edit' / 'q'\n>>");
  
  // main loop
  while(1){
    //異常入力で無限ループに陥らないようにしている
    //一度文字列として読み込んで、sscanf

    // input process
    scanf("%9s", input);

    if(strcmp(input, "q") == 0){
      break;
    }
    
    // ステップ実行
    if(strcmp(input, "step") == 0){
      modify(array);
      display(array);
      t++;
      printf("\nt = %d\n",t);
      printf("\n'run' / 'step' / 'edit' / 'q'\n>>");
      continue;
    }

    // 実行
    if(strcmp(input, "run") == 0){
      while(1){
	display(array);
	printf("\nt = %d\n", t);
	modify(array);
	t++;
	usleep(CLOCK * 1000);
      }
      input[0] = '\0';
      continue;
    }

    //編集モード
    if(strcmp(input, "edit") == 0){
      edit(array);
      
      //write to file
      fp = fopen("savedata.txt", "w");
      for(i = 0; i < HEIGHT; i++){
	for(j = 0; j < WIDTH; j++){
	  fputc(array[i][j], fp);
	}
      }      
      fclose(fp);
      
      input[0] = '\0';
      display(array);
      printf("\n'run' / 'step' / 'edit' / 'q'\n>>");
      continue;
    }

    // error
    display(array);
    printf("\ninvalid\n");
    printf("\n'run' / 'step' / 'edit' / 'q'\n>>");
  }
  printf("End\n");
  return 0;
}


void display(const char array[HEIGHT][WIDTH]){
  int i, j;
  system("clear");
  for(i = 1; i < HEIGHT - 1; i++){
    for(j = 1; j < WIDTH - 1; j++){
      printf("%c ", array[i][j]);
    }
    printf("\n");
  }  
}

void modify(char array[][WIDTH]){
  int i, j, cnt;
  char temp[HEIGHT][WIDTH]; //逐次書き換えるとバグる。一時保存しておいてまとめて書き換える。

  //judge
  for(i = 1; i < HEIGHT - 1; i++){
    for(j = 1; j < WIDTH - 1; j++){
      cnt = 0;

      if(array[i-1][j-1] == LIVE) {cnt++;}
      if(array[i-1][j  ] == LIVE) {cnt++;}
      if(array[i-1][j+1] == LIVE) {cnt++;}
      if(array[i  ][j-1] == LIVE) {cnt++;}
      if(array[i  ][j+1] == LIVE) {cnt++;}
      if(array[i+1][j-1] == LIVE) {cnt++;}
      if(array[i+1][j  ] == LIVE) {cnt++;}
      if(array[i+1][j+1] == LIVE) {cnt++;}
      
      
      if(array[i][j] == DEAD){
	if(cnt == 3){
	  temp[i][j] = LIVE;
	}
	else{
	  temp[i][j] = DEAD;
	}
      }
      else{
	if(cnt <= 1 || cnt >= 4){
	  temp[i][j] = DEAD;
	}
	else{
	  temp[i][j] = LIVE;
	}
      }
      
    }
  }

  //書き換え
  for(i = 1; i < HEIGHT - 1; i++){
    for(j = 1; j < WIDTH - 1; j++){
      array[i][j] = temp[i][j];
    }
  }
  
}

void edit(char array[HEIGHT][WIDTH]){
  int x = 0, y = 0; 
  char c, temp;
  while(1){
    temp = array[y + 1][x + 1];
    array[y + 1][x + 1] = '*';
    display(array);
    array[y + 1][x + 1] = temp;
    printf("\nEdit mode\n\nwasd: move cursor(*) / e: select / q: save changes and exit\n>>\n");
    c = getchar();
    switch(c){
    case 'q':
      return;
      break;
    case 'd': //right
      x = (x + 1) % (WIDTH - 2);
      break;
    case 'a': //left
      x = (x + (WIDTH - 2) - 1) % (WIDTH - 2);
      break;
    case 's': //down
      y = (y + 1) % (HEIGHT - 2);
      break;      
    case 'w': //up
      y = (y + (HEIGHT - 2) - 1) % (HEIGHT - 2);
      break;
    case 'e': //select
      array[y + 1][x + 1] = (array[y + 1][x + 1] == LIVE)? DEAD : LIVE;
      break;
    }
 
  }
}
