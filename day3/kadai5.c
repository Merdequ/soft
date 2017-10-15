/*
N枚のコインを，当選金と当選確率が異なるk台のスロットマシン(ただし終始一定)に賭けるとき，
得られる当選金をできるだけ大きくするプログラムをつくる。

方針:
基本的に，何回か適当にかけてみて，その結果次第で残りをどこにかけるかを決めるという方針になる。
コインの枚数をN，スロットマシンの数をk, 
各スロットマシンの当選率と当選額をそれぞれ p(i), r(i) (0 < i < k - 1)とする。

スロットマシン i から得られる当選金の期待値は賭けるコイン1つにつき，p(i) * r(i) である。

プレイヤーが得る情報は，N, k と賭けた結果のみである。(p や r はわからない)
儲かり具合  := (最終的に手にした当選金 / 掛け金N)  の期待値 e を最大化する戦略を考えたい。

問題を簡略化するため，以下のようなシンプルな戦略を考えることにする。

戦略 T(x) : 始めのx回はすべてのスロットに均等にかけ，
スロット i から得た当選金の平均値を E(i)p(i) * r(i) とする。
この E(i) が最大であったマシンに残りの N - x 回をかける。

問題にN枚賭けるとあるので，賭けない方がプラスという場合は考えない

戦略 T(x) による e を最大化するような x を考えてみる。
ここで，理想的な賭け方すなわち，N 枚すべてのコインを期待値最大であるスロットに
賭けた場合の期待値 e_max との比較し，その差 e - e_max (0以下である)を基準にする。

戦略 T(x) をとった場合，理想的な賭け方との差が生じる要因は２つにわけられて，
１つ目は，初めのx回で期待値最大のスロット以外のスロットにかけてしまうことによる損失，
２つ目は，期待値最大のスロット(スロット i_max とする)よりも別のスロットの方が
x回の平均 E(i)が大きくなってしまったために，
残りの N - x 回を期待値最大のマシン以外のマシンに賭けることによる損失である。

前者は x * ((全スロットの期待値の平均) - (期待値最大のスロットの期待値))
後者は (N - x) * Σ[i=0...k](スロット i で E(i)が最大となる確率) * (スロット i の期待値 - 期待値最大のスロットの期待値)
と表される。

x が最適な値より大きい場合は前者が大きくなり，小さい場合には後者が大きくなる。
一般の場合に最適なxを求めるのは難しそう。
(しかも，xが求まってもT(x)で表される単純な戦略の中で最適というだけである。)

なので，Nが十分大きいという条件下では最適となるような戦略を考えることにする。
つまり，N → ∞ において，e - e_max → 0 となる戦略が目標である。

1. x がマシンの数 k と 当選率 p(i) の逆数に比べて十分大きく，
2. x / N → 0 [N → ∞]

という条件を満たしていれば，戦略 T(x) は目標の戦略として相応しい。

実際，条件1から期待値最大のスロット以外がテストベットで最大の平均を出す確率は0になり，
後者の損失は無視することができ，
条件2から前者の損失も0に収束する。

したがって，この戦略は一般的全くもって最適戦略ではないが，
Nを十分大きくすれば，最適戦略と同じ期待値に収束する。
この方針でプログラムを実装することにした。

xの選び方は上の条件を満たせばなんでもよいが，収束が早そうなものを考えて，
x = N / log(N) を選んだ。(小さいNでもバグを吐かないように少しいじったがオーダーは同じ)

Nが十分大きい場合，均等になれば最初のx回の具体的な賭け方はそれほど重要ではないので，
ランダムベットのままにした。
*/



#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define K 5 // スロットマシンの数
#define N 1000000 // コインの数．採点時には1,000,000などの大きな数にする．
int bet(int k); //変更不可
int max_index(double array[], int n);


int main() { //自由に変更して良い
  srand((unsigned) time(NULL));
  int credit = N, reward=0, sum=0, selectslot, bestslot, times[K];
  double ave[K];

  for(int i = 0; i < K; i++){ //配列を初期化
    ave[i] = times[i] = 0;
  }
  
  printf("N = %d, K = %d\n\n", N, K);
  printf("Test betting...\n");
  
  while(credit-- > N - N / (int)(log(N) + 1)){
    selectslot = rand() % K; //賭けるスロットをランダムに選択
    reward = bet(selectslot);
    ave[selectslot] += reward; //このスロットからの獲得金額を記録
    times[selectslot]++; //このスロットに掛けた回数を記録
    sum += reward; //合計当選額に反映
  }

  for(int i = 0; i < K; i ++){
    if(times[i] != 0){
      ave[i] /= times[i]; //和を平均に変換する
    }
    //debug
    printf("slot %d : bet %d times and average gain was %f\n", i, times[i], ave[i]);
  }

  bestslot = max_index(ave, K);
  printf("\nEstimated slot %d is most profitable\nBetting the remaining %d coins in slot %d\n\n", bestslot, credit, bestslot);
  
  while(credit-- > 0){
    reward = bet(bestslot);
    sum += reward; //合計当選額に反映
  }

  printf("sum = %f\n",(double) sum / N );

  return 0;
}

int max_index(double array[], int n){
  int i_max = 0;
  double max = array[0];
  for(int i = 1; i < n; i++){
    if(array[i] > max){
      i_max = i;
      max = array[i];
    }
  }
  return i_max;
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
