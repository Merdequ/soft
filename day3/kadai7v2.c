/*
アルファベット２文字を単位とした出現回数を数える。
出現回数の順に並び替えるプログラムを追加した。
二次元配列の中身をソートするということが最初スムーズにできなかった。
調べて考えた結果，1次元配列に2次元配列としてアクセスできるようにして，
1次元配列をqsortで並び替えるという方法をとることにした。
c言語の配列や，ポインタのことがちょっとわかった気がする。
 */
#include <stdio.h>
#include <stdlib.h>
#define NALPHA 26

typedef struct { 
    int c1, c2, count;
  } Twochar; //２文字単位での出現回数を保存した構造体


int cmp(const void *a, const void *b);

int main()
{
  int c, i, j;
  int first, second;

  Twochar twins_flat[NALPHA * NALPHA]; //1次元配列として定義(ソートを可能にするため)
  Twochar *twins[NALPHA]; //Twochar型へのポインタを要素に持つ配列
  for( i = 0; i < NALPHA; i++){
    twins[i] = &twins_flat[i * NALPHA]; //1次元配列を 26 ずつ区切ったときの先頭のアドレスを代入(二次元配列としてアクセスできる)
  }
  
  for( i = 0 ; i < NALPHA ; i++ ) { //初期化
    for( j = 0 ; j < NALPHA ; j++ ) {
      twins[i][j].count = 0;
      twins[i][j].c1 = i;
      twins[i][j].c2 = j;
    }
  }

  //文字入力，カウント処理
  second = ' ';
  while( ( c = getchar() ) != EOF ) {
    first = second;
    second = c;
    if(first >= 'a' && first < 'a' + NALPHA && second >= 'a' && second < 'a' + NALPHA) {
      twins[first-'a'][second-'a'].count++;
    }
  }

  //ソート
  qsort(twins_flat, sizeof(twins_flat) / sizeof(twins_flat[0]), sizeof(twins_flat[0]), cmp);

  // 表示
  for( i = 0 ; i < NALPHA ; i++ ) {
    for( j = 0 ; j < NALPHA ; j++ ) {
      printf ("[%c][%c] = %d\n", 'a' + twins[i][j].c1, 'a' + twins[i][j].c2, twins[i][j].count );
    }
  }

  return 0;
}

int cmp(const void *a, const void *b){ //Twochar型構造体比較用関数(countの値の大小で比較)
  return ((Twochar *)a)->count - ((Twochar *)b)->count;
}
