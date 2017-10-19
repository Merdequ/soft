// ポインタへの書き換え。練習
//

#include <stdio.h>

int main()
{
  int sum, i;
  int *pi = &i;
  int *psum = &sum;
  *pi = 0;
  *psum = 0;
  
  for (*pi=0; *pi<=10; (*pi)++){
    *psum += *pi;
  }

  printf("sum = %d\n", *psum);
  return 0;
}
