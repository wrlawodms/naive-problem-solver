#include<stdio.h>
#include<math.h>

int min(int a, int b) {
  return a < b ? a: b; 
}

int main() {
  
  int N;
  int line[3][1000];
  int i, j;
  
  const int R = 0;
  const int G = 1;
  const int B = 2;


  scanf("%d", &N);
  scanf("%d %d %d", &line[R][0], &line[G][0], &line[B][0]);
  for(i=1; i<N; i++) {
    int r, g, b;
    scanf("%d %d %d", &r, &g, &b);
    
    for (j=0; j<3; j++) {
      if (j == R) {
        line[R][i] = min(line[G][i-1]+r,
                         line[B][i-1]+r);
      }else if (j == G) {
        line[G][i] = min(line[R][i-1]+g,
                         line[B][i-1]+g);
      }else if (j == B) {
        line[B][i] = min(line[R][i-1]+b,
                         line[G][i-1]+b);
      }
    }
  }
  printf("%d", min(min(line[R][N-1], line[G][N-1]), line[B][N-1]));

  return 0;
}
