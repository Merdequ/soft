/*
ファイルの文字列をラングレングス圧縮して出力する
データが連続してないとデータが膨らんでしまう。
 */

#include <stdio.h>

#define MAX_SIZE 100000
#define MAX_FILENAME 100

int main(int argc, char *argv[]){
  FILE *fp;
  int i = 0, length, outlen = 0, sequence = 0;
  char data[MAX_SIZE];


  if(argc != 3){
    printf("Error\n引数1: 入力データファイル\n引数2: 出力先ファイル\n");
    return 0;
  }
  
  // ファイルのデータを配列に読み込み
  if((fp = fopen(argv[1], "r")) == NULL){
    printf("ファイル'%s'は存在しません。\n", argv[1]);
  }
  else{
    while((data[i] = fgetc(fp)) != EOF){
      i++;
    } //
    
    length = i;
    fclose(fp);
  }

  // write to file
  fp = fopen(argv[2],"w");
  for(i = 0; i <= length; i++){
    sequence++;
    if(data[i] != data[i + 1]){
      printf("%c%d",data[i],sequence);
      fprintf(fp, "%c%d", data[i], sequence);
      outlen += 2;
      sequence = 0;
    }
  }
  fclose(fp);

  printf("圧縮率: %d%%\n",100 * outlen / length);
  return 0;
}
