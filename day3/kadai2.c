#include <stdio.h>
#include <stdlib.h>

int main(void){
  char input;
  char gu[] = "グー", ch[] = "チョキ", pa[] = "パー";
  char* array[] = {gu, ch, pa};
  // arrayはグー　チョキ　パー　の３つの文字列を含んだ配列
  int player, cp;
  // arrayのインデックス(どの手を出したか)を表す
  // 0: グー 1:チョキ 2:パー
  int seed = 0, temp, win = 50, draw = 33;
  //win, draw はそれぞれプレイヤーの勝率、引き分け率
  
  srand(seed);
  while((input = getchar()) != 'q'){
    if(input != 'g' && input != 'c' && input != 'p'){
      continue;
    }
    temp = rand() % 100;

    switch(input){
    case 'g':
      player = 0;
      break;
    case 'c':
      player = 1;
      break;
    case 'p':
      player = 2;
      break;
    }
    
    if(temp < win){
      cp = (player + 1) % 3;
      printf("あなたは%sをだしました. 私は%sを出しました. あなたの勝ち！\n",array[player],array[cp]);
    }
    else if(temp < win + draw){
      cp = player;
      printf("あなたは%sをだしました. 私は%sを出しました. あいこ！\n",array[player],array[cp]);
    }
    else{
      cp = (player + 2) % 3;
      printf("あなたは%sをだしました. 私は%sを出しました. 私の勝ち！\n",array[player],array[cp]);
    }
  }
}
