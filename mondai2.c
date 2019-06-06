#include <stdio.h>
#include <string.h>
#include <time.h>
#define SIZE 1001 //文字列の長さの限界（'\0'の文字が含まれる）

int main(void){
  //入力：文字列１(str1)と文字列２(str2)
  //出力：最長共通部分列(out)
  char str1[SIZE]={},str2[SIZE]={},out[SIZE]={};
  //両方の文字列を互いに比べると、結果は行列refに格納する
  int ref[SIZE+1][SIZE+1];
  //カウンタ：i,j,k
  //str1とstr2の長さ：len1,len2
  //len1とlen2の内にどちら低いか : len
  int i,j,len1,len2,k,len;
  //両方の文字列を読み込む
  scanf("%s",str1);
  scanf("%s",str2);
  //両方の文字列の長さを計算する
  len1 = strlen(str1);
  len2 = strlen(str2);
  len = len1>len2? len2:len1;
  //行列refを記入する
  for(i=1;i<=len;i++){
    for(j=i;j<=len1;j++){
      if(str1[j-1]==str2[i-1]) ref[i][j] = ref[i-1][j-1] + 1;
      else ref[i][j] = ref[i-1][j] > ref[i][j-1]? ref[i-1][j] : ref[i][j-1];
    }
    for(j=i+1;j<=len2;j++){
      if(str1[i-1]==str2[j-1]) ref[j][i] = ref[j-1][i-1] + 1;
      else ref[j][i] = ref[j-1][i] > ref[j][i-1]? ref[j-1][i] : ref[j][i-1];
    }
  }
  //行列refから最長共通部分列を得て、結果はoutに代入する
  i = len2;
  j = len1;
  k = ref[i][j];
  while(k>0){
    if(str1[j-1]==str2[i-1]){
      out[k-1] = str1[j-1];
      k--;
      i--;
      j--;
    }
    else if(ref[i][j-1] > ref[i-1][j]) j--;
    else i--;
  }
  //結果をプリントする
  printf("%s\n",out);
  return 0;
}


