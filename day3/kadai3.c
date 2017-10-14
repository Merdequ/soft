#include <stdio.h>
#include <math.h>

int main(void){
  printf("#x\tsin(x)");
  for(double k = -5; k <= 5; k += 0.01){
    printf("%f\t%f\n",k * M_PI, sin(k * M_PI));
  }
}
