#include <iostream>

using namespace std;


int M, N;
int **arr;
int ** path;
unsigned int cnt = 0;

int dfs(int x, int y) {
  
  if (path[x][y] != -1) {
    return path[x][y];
  }

  int result = 0;

  if (x-1 >= 0 && arr[x-1][y] < arr[x][y]) {
    result += dfs(x-1, y);
  }
  if (x+1 < M && arr[x+1][y] < arr[x][y]) {
    result += dfs(x+1, y);
  }
  if (y-1 >= 0 && arr[x][y-1] < arr[x][y]) {
    result += dfs(x, y-1);
  }
  if (y+1 < N && arr[x][y+1] < arr[x][y]) {
    result += dfs(x, y+1);
  }
  path[x][y] = result;

/*
  for (int i=0; i<M; i++) {
    for (int j=0; j<N; j++) {
      cout << path[i][j] << " ";
    }
    cout << endl;
  }
  cout << endl;
  */
  return result;
}

int main() {

  cin >> M >> N;
  arr = new int*[M];
  path = new int*[M];

  for(int i=0; i<M; i++) {
    arr[i] = new int[N];
    path[i] = new int[N];
    for (int j=0; j<N; j++) {
      path[i][j] = -1;
    }
  }

  path[M-1][N-1] = 1;
    
  for (int i=0; i<M; i++) {
    for (int j=0; j<N; j++) {
      cin >> arr[i][j];
    }
  }
  dfs(0,0);
  cout << path[0][0];

  return 0;
}
