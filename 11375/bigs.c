#include<stdio.h>
#include<memory.h>
#define SRC 0
#define DEST 1

int flow(int N, int M, int src, int dest);

int arr[2002][2002] = {0,};
int visited[2002];

int main(){
    int N, M;
    int i,j;
    int cnt;
    scanf("%d %d", &N, &M);
    for(i=0; i<N; i++){
        arr[SRC][i+2] = 1;
    }
    for(i=N; i<N+M; i++){
        arr[i+2][DEST] = 1;
    }
    for(i=0; i<N; i++){
        int cnt;
        scanf("%d", &cnt);
        for(j=0; j<cnt; j++){
            int work;
            scanf("%d", &work);
            arr[i+2][N+work-1+2]=1;
        }
    }

    while(flow(N, M, SRC, DEST)){
        memset(visited, 0, sizeof(visited));
    }

    for(i=0; i<N; i++){
        if(arr[SRC][i+2] == 0)
            cnt++;
    }
    printf("%d", cnt);

    return 0;
}


int flow(int N, int M, int src, int dest){
    int i,j;
    visited[src] = 1;
    for(i=0; i<N+M+2; i++){
        if(src == DEST){
            return 1;
        }
        if(arr[src][i]>0 && visited[i]!=1){
            if(flow(N, M, i, dest)){
                arr[src][i] -= 1;
                arr[i][src] += 1;
                return 1;
            }
        }
    }
    return 0;
}

