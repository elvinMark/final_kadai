#include <stdio.h>
#include <stdlib.h>

int main(void){
  double a,b,c;
  int i,n;
  double sum_x = 0,sum_x2=0,sum_x3=0,sum_x4=0,sum_y = 0,sum_xy = 0,sum_x2y=0,det;
  double temp_x,temp_y;
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%lf %lf",&temp_x,&temp_y);
    sum_x += temp_x;
    sum_y += temp_y;
    sum_x2 += temp_x*temp_x;
    sum_xy += temp_x*temp_y;
    sum_x3 += temp_x*temp_x*temp_x;
    sum_x4 += temp_x*temp_x*temp_x*temp_x;
    sum_x2y += temp_x*temp_x*temp_y;
  }
  det = sum_x4*(sum_x2*n - sum_x*sum_x) + sum_x3*(sum_x2*sum_x - n*sum_x3) + sum_x2*(sum_x3*sum_x - sum_x2*sum_x2);
  a = ((n*sum_x2 - sum_x*sum_x)*sum_x2y -  (n*sum_x3 - sum_x*sum_x2)*sum_xy + (sum_x3*sum_x - sum_x2*sum_x2)*sum_y)/det;
  b = (-(n*sum_x3 - sum_x*sum_x2)*sum_x2y +  (-sum_x2*sum_x2 + n*sum_x4)*sum_xy - (sum_x*sum_x4 - sum_x3*sum_x2)*sum_y)/det;
  c = ((sum_x3*sum_x - sum_x2*sum_x2)*sum_x2y - (sum_x*sum_x4 - sum_x3*sum_x2)*sum_xy + (sum_x4*sum_x2 - sum_x3*sum_x3)*sum_y)/det;
  printf("%.4lf %.4lf %.4lf\n",a,b,c);
  return 0;
}
