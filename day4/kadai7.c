// 文字列をコピーする関数の作成
//

#include <stdio.h>
#define MAX_LEN 30

void strcpy1(const char *s, char *t);

int main()
{
  char str1[MAX_LEN] = "Wagahai ha neko dearu", str2[MAX_LEN] = "namae ha mada nai";
  printf("str1: %s\nstr2: %s\n",str1,str2);
  strcpy1(str1, str2);
  printf("strcpy1 !!\n");
  printf("str1: %s\nstr2: %s\n",str1,str2);
}

void strcpy1(const char *s, char *t) {
    int i = 0;
    do{
      *(t + i) = *(s + i);
      i++;
    } while(s[i] != '\0');
}
