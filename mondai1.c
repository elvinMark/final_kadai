#include <stdio.h>
#include <stdlib.h>

int main(void){
  double a,b;
  int i,n;
  double sum_x = 0,sum_x2=0,sum_y = 0,sum_xy = 0,det;
  double temp_x,temp_y;
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%lf %lf",&temp_x,&temp_y);
    sum_x += temp_x;
    sum_y += temp_y;
    sum_x2 += temp_x*temp_x;
    sum_xy += temp_x*temp_y;
  }
  det = sum_x2*n - sum_x*sum_x;
  a = (n*sum_xy - sum_x*sum_y)/det;
  b = (-sum_x*sum_xy + sum_x2*sum_y)/det;
  printf("%.4lf %.4lf\n",a,b);
  return 0;
}
