/*
世界のナベアツ的なことをする
3の倍数または3を含む数字の後に!!!を付ける
 */


#include <stdio.h>
#include <math.h>
int isaho(int);

int main(void){
  for(int i = 1; i <= 1000; i++){
    printf("%d%s\n", i, isaho(i)? "!!!" : "");
  }
}

//3の倍数またはいずれかの桁に3を含む数字を受け取った場合は1、そうでない場合は0を返す
int isaho(int n){
  int digit;
  if(n % 3 == 0){
    return 1;
  }
  else{
    digit = 1;
    //nの最大桁を超えない間、各桁について3であるかを判定
    while(n > pow(10, digit - 1)){
      if((n / (int)pow(10, digit - 1)) % 10 == 3){
	return 1; //3があれば関数を抜ける
      }
      digit++;
    }
  }
  return 0;
}
