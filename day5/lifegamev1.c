/*
LIFE GAME
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

#define WIDTH 10
#define HEIGHT 10
#define LIVE 'O'
#define DEAD '-'
#define CLOCK 3

int main(void){
  char array[WIDTH][HEIGHT];
  int cnt;
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
  for(i = 1; i < WIDTH - 1; i++){
    for(j = 1; j < HEIGHT - 1; j++){
      printf("%c ", array[i][j]);
    }
    printf("\n");
  }


  
  // main loop
  while(1){
    
    // modify array
    for(i = 1; i < WIDTH - 1; i++){
      for(j = 1; j < HEIGHT - 1; j++){
	// judge
	cnt = 0;
	if(array[i-1][j-1] == LIVE) cnt++;
	if(array[i-1][j  ] == LIVE) cnt++;
	if(array[i-1][j+1] == LIVE) cnt++;
	if(array[i  ][j-1] == LIVE) cnt++;
	if(array[i  ][j+1] == LIVE) cnt++;
	if(array[i+1][j-1] == LIVE) cnt++;
	if(array[i+1][j  ] == LIVE) cnt++;
	if(array[i+1][j+1] == LIVE) cnt++;

	if(array[i][j] = DEAD){
	  if(cnt == 3){
	    array[i][j] == LIVE;
	  }
	}
	else{
	  if(cnt <= 1 || cnt >= 4){
	    array[i][j] = DEAD;
	  }
	}
	/*
	if(cnt <= 1){
	  array[i][j] = DEAD;
	}
	else if(cnt == 2){
	  ;
	}
	else if(cnt == 3){
	  array[i][j] = LIVE;
	}
	else{
	  array[i][j] = DEAD;
	}
	*/
      }
    }

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
    for(i = 1; i < WIDTH - 1; i++){
      for(j = 1; j < HEIGHT - 1; j++){
	printf("%c ", array[i][j]);
      }
      printf("\n");
    }
    sleep(CLOCK);
  }
  printf("end successfully\n");
  return 0;
}
