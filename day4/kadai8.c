// 文字列を比較する関数の作成
//

#include <stdio.h>
#define MAX_LEN 50

int strcmp1(const char *s, char *t);

int main()
{
  char str1[MAX_LEN], str2[MAX_LEN];
  printf("first word: ");
  scanf("%s", str1);
  printf("second word: ");
  scanf("%s", str2);
  
  // printf("%d\n",'\0');
  // 終了コードは数字だと 0. 辞書順は "abc" < "adcdef" の用になってほしいので
  // 条件分岐で例外処理にする必要はなさそう
  printf("%d (-1: 1st < 2nd, 0: 1st = 2nd 1: 1st > 2nd)\n", strcmp1(str1,str2));
}

int strcmp1(const char *s, char *t) {  
  // 文字列比較関数
  // 辞書順で第一引数の方が大(あとに来る)なら +1, 小なら -1, 等しければ 0を返す
    int i = 0;
    do{
      if (s[i] > t[i]){
	return 1;
      }
      if (s[i] < t[i]){
	return -1;
      }
      i++;
    } while(s[i] != '\0' && t[i] != '\0');
    return 0;
}

