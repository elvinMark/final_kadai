#include <stdio.h>
#define HEIGHT 50
#define WIDTH 100

int game[HEIGHT][WIDTH];
int temp[HEIGHT][WIDTH];

void evolve(int,int);
void update_game(void);
void next_gen(void);

int main(void){
  FILE *init_state,*final_state;
  char buff[WIDTH+1];
  int i,j,n;
  init_state = fopen("input-final3.txt","r");
  final_state = fopen("output-final3.txt","w");
  for(i=0;i<HEIGHT;i++){
    fscanf(init_state,"%s",buff);
    for(j=0;j<WIDTH;j++)
      game[i][j] = buff[j] - '0';
  }
  scanf("%d",&n);
  for(i=0;i<n;i++){
    next_gen();
    update_game();
  }
  for(i=0;i<HEIGHT;i++){
    for(j=0;j<WIDTH;j++)
      fprintf(final_state,"%d",game[i][j]);
    fprintf(final_state,"\n");
  }
  fclose(final_state);
  fclose(init_state);
  return 0;
}

void next_gen(void){
  int i,j;
  for(i=0;i<HEIGHT;i++){
    for(j=0;j<WIDTH;j++)
      evolve(i,j);
  }
}

void evolve(int i,int j){
  int x,y,living = 0;
  for(x=-1;x<2;x++){
    for(y=-1;y<2;y++)
      living += game[(HEIGHT + x + i)%HEIGHT][(WIDTH + y + j)%WIDTH];
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

void update_game(void){
  int i,j;
  for(i=0;i<HEIGHT;i++){
    for(j=0;j<WIDTH;j++)
      game[i][j] = temp[i][j];
  }
}
