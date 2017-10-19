//ポインタの意味の確認
//ポインタを宣言する前に、mallocでint型一つ分の領域を確保している

#include <stdio.h>
#include <stdlib.h>

int main()
{
  int *p;
  p = (int *) malloc(sizeof(int) * 1);
  *p = 100;
  printf("*p = %d\n", *p);
  // int型へのポインタ p が指すアドレスの中身
  printf("p = %p\n", p);
  // ポインタ p が指すアドレス
  printf("&p = %p\n", &p);
  // ポインタ p が格納されているアドレス(p というポインタへのポインタ)
  return 0;
}
