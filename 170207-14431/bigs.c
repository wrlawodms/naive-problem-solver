#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int max_distance;

typedef struct vector{
    int x;
    int y;
} Vector;

int distance(Vector* v1, Vector*  v2){
    int dist_x = v1->x-v2->x;
    int dist_y = v1->y-v2->y;
    return sqrt(dist_x*dist_x+dist_y*dist_y);
}

int make_prims(int* prims, int max){
    int i, j;
    prims[0] = 1;
    for(i=1; i < max; i++){
        if (prims[i] == 1)
            continue;
        int m = sqrt(i);
        int is_prime = 1;
        for(j=2; j<=m; j++){
            if ( i+1 % j == 0){
                is_prime = 0;
                break;
            }
        }
        if (is_prime){
            for(j=i+i+1; j<max; j+=i+1){
                prims[j] = 1;
            }
        }
    }
}

int is_prime(int num, int* prims){
    if (num == 0)
        return 0;
    return !prims[num-1];
}


int **graph;
Vector vect[4002];

//dijkstra
int sh_path(int src_idx, int dest_idx, int vec_cnt){
    int *dist = malloc(vec_cnt*sizeof(int));
    int *visited = malloc(vec_cnt*sizeof(int));
    int i,j;
    int min;
    int min_v;
    int result;

    dist[src_idx] = 0;
    for(i=1; i<vec_cnt; i++){
        dist[i] = INT_MAX; //inf.
    }
    for(i=0; i<vec_cnt; i++){
        visited[i] = 0; 
    }

    for(i=0; i<vec_cnt; i++){ 
        min = INT_MAX;
        for(j=0; j<vec_cnt; j++){
            if ( !visited[j] && min > dist[j]){
                min = dist[j];
                min_v = j;    
            }
        }
    
        if (min_v == dest_idx) //already find dest 
            break; 
        if(min == INT_MAX){ //cant find dest-belonging graph
            break;
        }
        visited[min_v] = 1;
        for( j=0; j<vec_cnt; j++){
            if(graph[min_v][j]!=0 && dist[j] > dist[min_v]+graph[min_v][j]){
                dist[j] = dist[min_v]+graph[min_v][j];
            }
        }
    }
    result = dist[dest_idx] != INT_MAX? dist[dest_idx] : -1;
    free(dist);
    free(visited);
    return result;
}

int main(){
    Vector *src = &vect[0];
    Vector *dest = &vect[1];
    int src_idx=0, dest_idx=1;
    int vec_cnt;
    int i,j;
    int *prims;

    max_distance = 6000*sqrt(2);
    prims = malloc(max_distance*sizeof(int));
    make_prims(prims, max_distance);
    
    scanf("%d %d", &src->x, &src->y);
    scanf("%d %d", &dest->x, &dest->y);
    scanf("%d", &vec_cnt);

    vec_cnt += 2;
    graph = malloc((vec_cnt)*sizeof(int*));
    for(i=0; i<vec_cnt; i++)
        graph[i] = malloc((vec_cnt)*sizeof(int));
    
    int dist = distance(&vect[0], &vect[1]); 
    if(is_prime(dist, prims)){
        graph[0][1] = dist;
        graph[1][0] = dist;
    }
    for(i=2; i<vec_cnt; i++){
        scanf("%d %d", &vect[i].x, &vect[i].y);
        for(j=0; j<i; j++){
            int dist = distance(&vect[j], &vect[i]); 
            if(is_prime(dist, prims)){
                graph[j][i] = dist;
                graph[i][j] = dist;
            }
        }
    }
    printf("%d", sh_path(src_idx, dest_idx, vec_cnt));

    for(i=0; i<vec_cnt; i++)
        free(graph[i]);
    free(graph); 
    free(prims);
    
    return 0;
}

