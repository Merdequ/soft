/*
  パイこね変換を実行するプログラム
  初期値 0.1 で動かしてみると、N = 2 から 50 までは
  0.4と0.8(の近くの値)を繰り返し、N = 56 で 0 になる。

  正しく計算すれば、初期値が 2 進数の有限の少数で表せない数(例えば0.1 = 1/10など)は、
  パイコネ変換を何度繰り返し返しても 0 には行かないはず。
  逆に、pを整数として p / 2^n と表せるような数なら n+1 回変換すれば必ず 0 に行くはず。
  c言語では、小数は2進数の小数として扱われるので、入力した初期値によらずどこかで0に行く。

  メモ
  float型: 符号部 1bit 指数部 8bit 仮数部 23bit
  1.175494 * 10e-38 < float の絶対値 < 3.402823 * 10e+38

  double型: 符号部 1bit 指数部 11bit 仮数部 52bit
  2.225074 * 10e-308 < double の絶対値 < 1.797693 * 10e+308
 */

#include <stdio.h>

double pie(double x0, int N);

int main(){
  double x0;
  printf("initial value x0: ");
  scanf("%lf", &x0);
  for (int i = 0; i < 80; i++){
    printf("N = %4d: x = %5f\n", i, pie(x0, i));
  }
}

double pie(double x0, int N){
  double x = x0;
  for (int i = 0; i < N; i++){
    x = 2 * x;
    if (x > 1){
      x = 2 - x;
    }
  }
  return x;
}
