/*
あるアルファベットが登場したときに，次にあるアルファベットが登場する条件付確率を求め，
各アルファベットについて，その次に最も登場しやすいアルファベットと最も登場しにくいアルファベットを出力する。
 */

#include <stdio.h>
#define NALPHA 26

int main()
{
  int count[NALPHA][NALPHA];
  double prob[NALPHA][NALPHA];
  int c, i, j, sum; int first, second, minidx, maxidx;
  double min, max;

  for( i = 0 ; i < NALPHA ; i++ ) {
    for( j = 0 ; j < NALPHA ; j++ ) {
      count[i][j] = 0;
    }
  }
  second = ' ';

  while( ( c = getchar() ) != EOF ) { // 現在読み込んだ文字はcに代入されている
    first = second;
    second = c;
    if(first >= 'a' && first < 'a' + NALPHA && second >= 'a' && second < 'a' + NALPHA) {
      count[first-'a'][second-'a']++; // アルファベットが続く場合はカウントアップ
    }
  }

  for( i = 0 ; i < NALPHA ; i++ ) { // 確率を計算するループ
    sum = 0;

    for( j = 0 ; j < NALPHA ; j++ ) {
      /*?? iが特定のアルファベットの時の全ケースを求めてから、i->jとなる確率は、という計算なので、、、 ??*/
      sum += count[i][j];
    }

    for( j = 0 ; j < NALPHA ; j++ ) {
      prob[i][j] = (double)count[i][j]/(double)sum;
    }
  }

  for( i = 0 ; i < NALPHA ; i++ ) { //表示
    min = 2.0; // 初期化にあり得ない数字を入れておく
    max = -1.0; // 初期化にあり得ない数字を入れておく
    for( j = 0 ; j < NALPHA ; j++ ) {
      if( prob[i][j] < min && prob[i][j] > 0.0 ) {
	min = prob[i][j];
	minidx = j;
      }
      if( prob[i][j] > max ) {
	max = prob[i][j];
	maxidx = j;
      }
    }
    printf( "[%c]: min = %c (%e), max = %c (%e)\n", 'a'+i, 'a'+minidx, min, 'a'+maxidx, max );
  }

  return 0;
}
