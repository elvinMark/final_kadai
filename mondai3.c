#include <stdio.h>
#define HEIGHT 50
#define WIDTH 100

//game : game of lifeの盤面
//temp : 現在の盤面を進化するときに使う行列
int game[HEIGHT+2][WIDTH+2];
int temp[HEIGHT+2][WIDTH+2];

//evolve : 行列に(i,j)の要素の変化を計算する関数
void evolve(int i,int j);
//update_game : gameの更新する関数（tempをgameにコピーする関数）
void update_game(void);
//next_gen : gameの進化を行って、結果はtempに代入する
void next_gen(void);

int main(void){
  //初期状態があるファイル(init_state)と末期状態を出力するファイル(final_state)
  FILE *init_state,*final_state;
  //ファイルを読み込むとき、各行は文字列として読み込んでbuffに代入する
  char buff[WIDTH+1];
  //カウンタ：i,j
  //n : 何回進化させるか
  int i,j,n;
  //init_stateとfinal_stateの初期化
  init_state = fopen("input-final3.txt","r");
  final_state = fopen("output-final3.txt","w");
  //init_stateからgame of lifeの初期状態を読み込んで、gameに代入する
  for(i=1;i<=HEIGHT;i++){
    fscanf(init_state,"%s",buff);
    for(j=1;j<=WIDTH;j++)
      game[i][j] = buff[j-1] - '0';
  }
  //ターミナルからnの値を読み込む
  scanf("%d",&n);
  //n回で盤面を進化する
  for(i=0;i<n;i++){
    next_gen();
    update_game();
  }
  //結果はfinal_stateのファイルに出力する
  for(i=1;i<=HEIGHT;i++){
    for(j=1;j<=WIDTH;j++)
      fprintf(final_state,"%d",game[i][j]);
    fprintf(final_state,"\n");
  }
  //開いたファイルを閉じる
  fclose(final_state);
  fclose(init_state);
  return 0;
}

//各セルを進化する
void next_gen(void){
  int i,j;
  for(i=1;i<=HEIGHT;i++){
    for(j=1;j<=WIDTH;j++)
      evolve(i,j);
  }
}

//ルールを従って、(i,j)のセルを進化する
void evolve(int i,int j){
  int x,y,living = 0;
  for(x=-1;x<2;x++){
    for(y=-1;y<2;y++)
      living += game[i+x][j+y];
  }
  living -= game[i][j];
  if(game[i][j]){
    if(living == 2 || living == 3) temp[i][j] =  1;
    else temp[i][j]= 0;
  }
  else{
    if(living == 3)
      temp[i][j] = 1;
  }
}

//盤面を更新する
void update_game(void){
  int i,j;
  for(i=1;i<=HEIGHT;i++){
    for(j=1;j<=WIDTH;j++)
      game[i][j] = temp[i][j];
  }
}
