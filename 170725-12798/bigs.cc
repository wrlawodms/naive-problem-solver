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
     
      for(int j=x-2*r; j< x+2*r; j++){
        for(int k=y-2*r; k< y+2*r; k++){
          printf("%d ",arr[ORIGIN+j][ORIGIN+k]);
        }
        printf("\n");
      }
      
    }else{
      scanf("%d %d", &x, &y);
      printf("%d\n", arr[ORIGIN+x][ORIGIN+y]);
    }
  }  
  return 0;
}

void spoil(int seq_n, int x, int y, int r){
  if(r == -1)
    return;
  printf("%d %d\n", x,y);
  arr[x][y]++;
  seq[x][y] = seq_n;
  if(x-1 >= 0 && y-1 >=0 && seq[x-1][y-1] < seq_n)
    spoil(seq_n, x-1, y-1, r-1);
  if(x-1 >=0 && seq[x-1][y] < seq_n)
    spoil(seq_n, x-1, y, r-1);
  if(y-1 > 0 && seq[x][y-1] < seq_n)
    spoil(seq_n, x, y-1, r-1);
  if(x+1 < SIZE && seq[x+1][y] < seq_n)
    spoil(seq_n, x+1, y, r-1);
  if(y+1 < SIZE && seq[x][y+1] < seq_n)
    spoil(seq_n, x, y+1, r-1);
  if(x+1 < SIZE && y+1 < SIZE && seq[x+1][y+1] < seq_n)
    spoil(seq_n, x+1, y+1, r-1);
}

/*
int traverse(int obj_x, int obj_y, int* real_x, int* real_y){
  
}*/





