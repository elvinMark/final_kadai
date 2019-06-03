#include <stdio.h>
#include <math.h>
#define MAX_SIZE 5000 //点の数の限界
#define MAX_DIST 3000 //２つの点の距離の限界

//pos : 全ての点のx成分とy成分の情報を持っている配列
double pos[MAX_SIZE][2];
//cost : 行列の（i,j）は点iから点jまでの距離の切り上げの情報を持っている
int cost[MAX_SIZE][MAX_SIZE];

//dist : 点iから点jまでの距離を計算して、切り上げる関数
int dist(int i ,int j);
//calculate_cost : 行列costを記入する関数
void calculate_cost(int);


int main(void){
  //カウンタ　：　i,j,count
  //点の数　：　n
  //min, min_idx : ある行で一番低い値を調べるときに使う変数
  //min : 一番低い値
  //min_idx : minの位置
  int i,j,n,min,min_idx=0,count;
  //出力 : 点の順番 (order)
  //already : どの点もう過程したかを知らせる配列
  int order[MAX_SIZE],already[MAX_SIZE]={};
  //nの値を読み込む
  scanf("%d",&n);
  //点の情報を読み込む
  for(i=0;i<n;i++){
    scanf("%lf",&pos[i][0]);
    scanf("%lf",&pos[i][1]);
  }
  //行列costを記入する
  calculate_cost(n);
  //点の順番を計算する
  //最初の点は0
  order[0] = 0;
  //0の点はもう並んだので、alreadyの配列を更新する
  already[0] = 1;
  //i,countを初期化する、iはcostに現在の行番目
  count = 0;
  i=0;
  //まだ並んでいない点があれば振り返る
  while(count<n-1){
    //minはMAX_DISTとして初期化する（0だったら、0はどの距離でも低いので利用できない。しかしMAX_DISTは他の距離より大きいなので、利用できる）
    min = MAX_DIST;
    //minとmin_idxを探す
    for(j=0;j<n;j++){
      if(i!=j && (cost[i][j] < min) && !already[j]){
	min=cost[i][j];
	min_idx = j;
      }
    }
    //見つけたmin_idxは次の点を選ぶ
    already[min_idx] = 1;//min_idxの点はもう並んでいるのでalreadyを更新する
    i = min_idx;//現在の行番目(i)を更新する
    count++;//countも更新する
    order[count] = min_idx;//min_idxはorderに入れる
  }
  //順番をプリントする
  for(i=0;i<n-1;i++)
    printf("%d ",order[i]);
  printf("%d\n",order[i]);
  return 0;
}

//２つの点を互いの距離を計算する関数
int dist(int i,int j){
  double xd,yd;
  xd = pos[i][0] - pos[j][0];
  yd = pos[i][1] - pos[j][1];
  return (int)(sqrt(xd*xd + yd*yd) + 0.5);
}

//costを記入する関数
void calculate_cost(int n){
  int i,j;
  for(i=0;i<n;i++){
    for(j=0;j<n;j++)
      cost[i][j] = dist(i,j);
  }
}
