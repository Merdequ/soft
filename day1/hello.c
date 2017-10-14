#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define K 5 // スロットマシンの数
#define N 100 // コインの数．採点時には1,000,000などの大きな数にする．
int bet(int k); //変更不可

int main() { //自由に変更して良い
    srand((unsigned) time(NULL));
    int credit = N, reward=0, sum=0;
    int testSample = 1000000;
    int bestMachine = 0, maxEx = 0;
    int i,machine,temp;

    //test case
    for(machine = 0; machine <= K - 1; machine++){
      temp = 0;
      for(i = 0; i < testSample; i++){
	temp += bet(machine);
      }
      if(temp > maxEx){
	maxEx = temp;
	bestMachine = machine;
      }
      printf("%f\n", (double)temp / testSample);
      printf("%d\n", bestMachine);
    }

    //bet real money
    while(credit-- > 0){
      reward = bet(bestMachine);
      sum += reward;
    }
    printf("sum = %f\n",(double) sum / N );
        
    return 0;
}

// 以下の関数は変更不可
int bet(int k){ // 入力：スロットマシンの番号　出力：当選金
    // これは例であり，採点時には当選金と確率が変化する
    switch(k){
        case 0:
            if(rand() % 2 == 0){ // 2/2
                return 2;
            }else{
                return 0;
            }
            break;
        case 1:
            if(rand() % 7 == 0){ // 5/7
                return 5;
            }else{
                return 0;
            }
            break;
        case 2:
            if(rand() % 8 == 0){ // 10/8
                return 10;
            }else{
                return 0;
            }
            break;
        case 3:
            if(rand() % 40 == 0){ // 50/45
                return 50;
            }else{
                return 0;
            }
            break;
        case 4:
            if(rand() % 200 == 0){  // 100/200
                return 100;
            }else{
                return 0;
            }
            break;
        default:
            return 0;
    }
}
