/*
  コマンドライン引数の復習
 *


#include <stdio.h>

int main(int argc, char *argv[]){
  for(int i = 0; i <= 2; i++){
    printf("argv[%d]: %s\n", i, argv[i]);
  }
}
