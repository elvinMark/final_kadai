#include <stdio.h>
#include <stdlib.h>

int main(void){
  //傾きaと切片b
  double a,b;
  //カウンタiと点の数n
  int i,n;
  //全てのx成分の足し合わすsum_x、全てのx成分の二乗の足し合わすsum_x2、全てのy成分の足し合わすsum_y、全てのx成分掛けるy成分の足し合わすsum_xy、一次方程式系の行列の行列式det
  double sum_x = 0,sum_x2=0,sum_y = 0,sum_xy = 0,det;
  //入力しながら、一時的にx成分とy成分の情報はtemp_xとtemp_yに格納する
  double temp_x,temp_y;
  //点がいくつあるかをターミナルから読み込む
  scanf("%d",&n);
  //各点を読み込んで、読み込む共にsum_x,sum_y,sum_x2,sum_xyの量を更新する。
  for(i=0;i<n;i++){
    scanf("%lf %lf",&temp_x,&temp_y);
    sum_x += temp_x;
    sum_y += temp_y;
    sum_x2 += temp_x*temp_x;
    sum_xy += temp_x*temp_y;
  }
  //行列式を計算する
  det = sum_x2*n - sum_x*sum_x;
  //逆行列を使って、傾きと切片を計算する
  a = (n*sum_xy - sum_x*sum_y)/det;
  b = (-sum_x*sum_xy + sum_x2*sum_y)/det;
  //結果をプリントする
  printf("%.4lf %.4lf\n",a,b);
  return 0;
}
