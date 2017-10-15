/*
あるアルファベットが登場したときに，次にあるアルファベットが登場する条件付確率を求め，
各アルファベットについて，その次のアルファベットのエントロピーを計算し，出力する。

'a', 'i', 'n', 'o', 'u'などの次に来る文字のエントロピーは比較的大きく，3.5bit程の情報量を持っている。 
一方エントロピーが少ないものとしては，vの次の文字のエントロピーが0になっているのが興味深い。
課題8の実行結果から，'q'の後に来るアルファベットが100% 'u' になっていることがわかる。
"qu" 以外のつづりで'q'を含む英単語はもっぱら借用語に限られるようで，使用頻度は非常に低いらしい。
*/

#include <stdio.h>
#include <math.h>
#define NALPHA 26

int main()
{
  int count[NALPHA][NALPHA];
  double prob[NALPHA][NALPHA];
  double entropy[NALPHA];
  int c, i, j, sum; int first, second, minidx, maxidx;
  double min, max;

  for( i = 0 ; i < NALPHA ; i++ ) {
    entropy[i] = 0;
    for( j = 0 ; j < NALPHA ; j++ ) {
      count[i][j] = 0;
      prob[i][j] = 0;
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

  for( i = 0 ; i < NALPHA ; i++ ) { // 確率とエントロピー計算する
    sum = 0;

    for( j = 0 ; j < NALPHA ; j++ ) {
      /*?? iが特定のアルファベットの時の全ケースを求めてから、i->jとなる確率は、という計算なので、、、 ??*/
      sum += count[i][j];
    }

    for( j = 0 ; j < NALPHA ; j++ ) { //確率
      if(sum != 0){ // iが出ていない場合は，前の文字がiの時の条件付確率は0とする
	prob[i][j] = (double)count[i][j]/(double)sum;
      }
    }
    for( j = 0 ; j < NALPHA ; j++ ) { //エントロピーを計算
      if(prob[i][j] != 0){
	entropy[i] += prob[i][j] * (- log(prob[i][j]) / log(2));
      }
    }
  }

  for( i = 0 ; i < NALPHA ; i++ ) { //表示
    printf( "[%c]: ent = %e\n", 'a'+i, entropy[i] );
  }
  return 0;
}
