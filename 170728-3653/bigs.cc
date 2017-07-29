#include<iostream>
#include<cstring>

#define MAX 100000

int tree[MAX*2+1];
int arr[MAX+1]; 

int sum(int i){
  int result = 0;
  while(i>0){
    result += tree[i];
    i -= i & -i;
  }
  return result;
}

void update(int size, int i, int num){
  while(i <= size){
    tree[i] += num;
    i +=  i & -i;
  }
}

int main()
{
  int N;
  scanf("%d", &N);
  
  for(int i=0; i<N; i++){
    int n,m;
    int next;
    scanf("%d %d", &n, &m);

    memset(tree, 0, sizeof(tree));
    memset(arr, 0, sizeof(arr));
   
    next = m;

    for(int i=1; i<=n; i++)
      arr[i] = m+i;
    for(int i=m+1; i<=m+n+1; i++)
      update(m+n+1, i, 1);
    for(int j=0; j<m; j++){
      int q;
      scanf("%d", &q);
      printf("%d ", sum(arr[q]-1));
      update(m+n+1, arr[q], -1);
      update(m+n+1, next, 1);
      arr[q] = next--;
    }
    printf("\n"); 
  }
  return 0;
}
