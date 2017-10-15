/*
与えられた文字列中のアルファベットの個数をカウントする
カウントの結果から英文におけるアルファベットの情報量を求め，表示する。
 */

#include <stdio.h>
#include <math.h>
#define NALPHA 26 //アルファベットの種類

int main()
{
  int count[NALPHA];
  double prob[NALPHA];
  int c, i, sum;
  double entropy;
  for( i = 0 ; i < NALPHA ; ++i ) { //カウント結果を記録する配列を初期化する
    count[i] = 0;
  }

  while( ( c = getchar() ) != EOF ) {
    if(c >= 'a' && c < 'a' + NALPHA ) { // cがaからzの間アルファベットであれば、、、
      count[c-'a']++; // 該当するアルファベットのカウント結果を+1する。
    }
  }

  for( i = 0 ; i < NALPHA ; i++ ) { //文字の総数を計算
    sum += count[i];
  }
  
  for( i = 0 ; i < NALPHA ; i++ ) { //文字の出現確立を計算
    prob[i] = (double)count[i]/(double)sum;
  }
  for( i = 0 ; i < NALPHA ; i++ ) { //エントロピーを計算
    //printf("%c: %f\n",'a'+i,prob[i]);
    if(prob[i] != 0){
       entropy += prob[i] * (- log(prob[i]) / log(2));
    }
  }
  printf( "entropy = %e\n", entropy);

  return 0;
}
