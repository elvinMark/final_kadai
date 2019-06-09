#include <stdio.h>
#include <string.h>
#define SIZE 1001

int ref[SIZE+1][SIZE+1];
char str1[SIZE]={};
char str2[SIZE]={};
char out[SIZE]={};

void fill_matrix();
void print_str(int x,int y);

int main(void){
  scanf("%s",str1);
  scanf("%s",str2);
    
  fill_matrix();
  print_str(strlen(str2),strlen(str1));
  return 0;
}


void fill_matrix(){
  int i,j,len1,len2,len;
  len1 = strlen(str1);
  len2 = strlen(str2);
  len = len1>len2? len2:len1;
  for(i=1;i<=len;i++){
    for(j=i;j<=len1;j++){
      if(str1[j-1]==str2[i-1]) ref[i][j] = ref[i-1][j-1] + 1;
      else ref[i][j] = ref[i-1][j] > ref[i][j-1]? ref[i-1][j] : ref[i][j-1];
    }
    for(j=i+1;j<=len2;j++){
      if(str2[j-1]==str1[i-1]) ref[j][i] = ref[j-1][i-1] + 1;
      else ref[j][i] = ref[j-1][i] > ref[j][i-1]? ref[j-1][i] : ref[j][i-1];
    }
  }
}
void print_str(int x,int y){
  int i,j,k,temp;
  i = x;
  j = y;
  k = ref[i][j];
  if(k==0) printf("%s\n",out);
  else if(str1[j-1]==str2[i-1]){
    out[--k] = str1[--j];
    i--;
    print_str(i,j);
  }
  else if(ref[i][j-1] > ref[i-1][j]){
    while(ref[i][j-1] > ref[i-1][j]) j--;
    print_str(i,j);
  }
  else if(ref[i][j-1] < ref[i-1][j]){
    while(ref[i][j-1] < ref[i-1][j]) i--;
    print_str(i,j);
  }
  else{
    temp = i;
    while(ref[temp][j] == ref[temp-1][j]) temp--;
    print_str(temp,j);
    temp = j;
    while(ref[i][temp] == ref[i][temp-1]) temp--;
    print_str(i,temp);
  }
}

