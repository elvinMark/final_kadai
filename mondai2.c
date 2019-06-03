#include <stdio.h>
#include <string.h>
#define SIZE 1001


int main(void){
  char str1[SIZE]={},str2[SIZE]={},out[SIZE]={};
  int ref[SIZE+1][SIZE+1];
  int i,j,len1,len2,len,k;
  scanf("%s",str1);
  scanf("%s",str2);
  len1 = strlen(str1);
  len2 = strlen(str2);
  len = len1>len2? len1 : len2;
  for(i=1;i<=len;i++){
    for(j=i;j<=len;j++){
      if(str1[j-1]==str2[i-1]) ref[i][j] = ref[i-1][j-1] + 1;
      else ref[i][j] = ref[i-1][j] > ref[i][j-1]? ref[i-1][j] : ref[i][j-1];
    }
    for(j=i+1;j<=len;j++){
      if(str1[i-1]==str2[j-1]) ref[j][i] = ref[j-1][i-1] + 1;
      else ref[j][i] = ref[j-1][i] > ref[j][i-1]? ref[j-1][i] : ref[j][i-1];
    }
  }
  i = len;
  j = len;
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
  printf("%s\n",out);
  return 0;
}


