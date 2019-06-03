#include <stdio.h>
#include <math.h>
#define MAX_SIZE 5000
#define MAX_DIST 3000

double pos[MAX_SIZE][2];
int cost[MAX_SIZE][MAX_SIZE];

int dist(int,int);
void calculate_cost(int);


int main(void){
  int i,j,n,min,min_idx=0,count;
  int order[MAX_SIZE],already[MAX_SIZE]={};
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%lf",&pos[i][0]);
    scanf("%lf",&pos[i][1]);
  }
  
  calculate_cost(n);

  order[0] = 0;
  already[0] = 1;
  count = 0;
  i=0;
  while(count<n-1){
    min = MAX_DIST;
    for(j=0;j<n;j++){
      if(i!=j && (cost[i][j] < min) && !already[j]){
	min=cost[i][j];
	min_idx = j;
      }
    }
    already[min_idx] = 1;
    i = min_idx;
    count++;
    order[count] = min_idx;
  }
  for(i=0;i<n-1;i++)
    printf("%d ",order[i]);
  printf("%d\n",order[i]);
  return 0;
}

int dist(int i,int j){
  double xd,yd;
  xd = pos[i][0] - pos[j][0];
  yd = pos[i][1] - pos[j][1];
  return (int)(sqrt(xd*xd + yd*yd) + 0.5);
}

void calculate_cost(int n){
  int i,j;
  for(i=0;i<n;i++){
    for(j=0;j<n;j++)
      cost[i][j] = dist(i,j);
  }
}
