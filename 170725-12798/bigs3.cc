#include<iostream>
#include<math.h>

using namespace std;
struct XYR{
  int x;
  int y;
  int r;
};
int main(){
 
  //memset(arr, 0, sizeof(int)*SIZE*SIZE);
  //memset(seq, 0, sizeof(int)*SIZE*SIZE);
  
  int N, Q;
  int cnt = 0;
  struct XYR xyr[200000];
  
  scanf("%d %d", &N, &Q);
  
  for(int i=0; i<Q; i++){
    int what;
    scanf("%d", &what);
    
    if(what == 1){
      int x, y, r;
      scanf("%d %d %d", &x, &y, &r);
      xyr[cnt].x = x;
      xyr[cnt].y = y;
      xyr[cnt].r = r;
      cnt++;
    }else{
      int x,y;
      scanf("%d %d", &x, &y);
      int result=0;
      for(int j=0; j<cnt; j++){
        int dx = xyr[j].x-x;
        int dy = xyr[j].y-y;
        int r = xyr[j].r;
        int dist;
        if(dx*dy<0)
          dist = abs(dx)+abs(dy);
        else
          dist = abs(dx) > abs(dy) ? abs(dx) : abs(dy);
        if(dist <= r)
          result++;
      }
      printf("%d\n", result);
    }
  }  
  return 0;
}
