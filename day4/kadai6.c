// 文字列の長さを求める関数の作成
//

#include <stdio.h>

int strlen1(const char *s);

int main()
{
    char *str = "Supercalifragilisticexpialidocious";
int len = strlen1(str);
    printf("length of '%s' is %d\n",str,len);
}

int strlen1(const char *s) {
    int i = 0;
    while(s[i] != '\0'){
        i++;
    }
    return i;
}
