#include <iostream>

using namespace std;

int N,M;
int graph[500][500];
int cache[500][500];

int findWay(int sx,int sy)
{
	if(sx==N-1 && sy==M-1)
		return 1;
	
	int& ret = cache[sy][sx];
	if(ret!=-1) return ret;
	ret = 0;
	
	int dx[4] = {-1,0,1,0};
	int dy[4] = {0,1,0,-1};
	
	for(int i=0; i<4; i++)
	{
		int nx = sx+dx[i];
		int ny = sy+dy[i];
		
		if(nx>=0 && nx<N && ny>=0 && ny <M)
		{
			if(graph[ny][nx] < graph[sy][sx])
			{
				ret+=findWay(nx,ny);	
			}
		}
	}
	return ret;
}

int main()
{
	freopen("1520_input.txt","r",stdin);
	
	scanf("%d %d",&M,&N);
	
	for(int i=0; i<M; i++)
		for(int j=0; j<N; j++)
			cache[i][j] = -1;
	
	for(int h=0; h<M; h++)
	{
		for(int w=0; w<N; w++)
		{
			scanf("%d",&graph[h][w]);
		}
	}
	
	printf("%d\n",findWay(0,0));
	
	return 0;
}
