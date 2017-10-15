/*
char型２次元配列から要素を取り出して pen pineapple apple pen と表示する
 */

#include <stdio.h>
int main(void){
  char starray[3][10] = {"pen", "apple", "pineapple"};
  printf("%s %s %s %s\n", starray[0], starray[2], starray[1], starray[0]);
  return 0;
}
