#include<iostream>
#include<queue>

#define SIZE 4001
#define ORIGIN SIZE/2

using namespace std;

int arr[SIZE][SIZE];
int seq[SIZE][SIZE];

void spoil(int seq_n, int x, int y, int r);

int main(){
 
  //memset(arr, 0, sizeof(int)*SIZE*SIZE);
  //memset(seq, 0, sizeof(int)*SIZE*SIZE);
  
  int N, Q;
  int seq = 0;

  scanf("%d %d", &N, &Q);
  
  for(int i=0; i<Q; i++){
    int what;
    int x, y, r;
    scanf("%d", &what);
    
    if(what == 1){
      scanf("%d %d %d", &x, &y, &r);
      spoil(++seq, ORIGIN+x, ORIGIN+y, r);
      /*     
      for(int j=x-2*r; j< x+2*r; j++){
        for(int k=y-2*r; k< y+2*r; k++){
          printf("%d ",arr[ORIGIN+j][ORIGIN+k]);
        }
        printf("\n");
      }
      */
    }else{
      scanf("%d %d", &x, &y);
      printf("%d\n", arr[ORIGIN+x][ORIGIN+y]);
    }
  }  
  return 0;
}

void spoil(int seq_n, int x, int y, int r){
  int sx = x - r;
  int sy = y - r;
  
  for(int i=0; i <= r; i++){
    for(int j=0; j <= r+i; j++){
      if(sx+i < 0 || sx+i >= SIZE)
        continue;
      arr[sx+i][sy+j]++;
    }
  } 
  for(int i=0; i < r; i++){
    for(int j=0; j < r*2-i; j++){
      if(sx+i < 0 || sx+i >= SIZE)
        continue;
      arr[sx+i+r+1][sy+j+i+1]++; 
    }
  }
}

/*
int traverse(int obj_x, int obj_y, int* real_x, int* real_y){
  
}*/





