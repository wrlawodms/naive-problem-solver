#include <stdio.h>
#include <queue>
#include <algorithm>
#include <string.h>
using namespace std;

int visit[100001];
queue<int> q;

int find(int position,int obj)
{
	if(position==obj)
		return 0;
	
	q.push(position);
	visit[position] = 0;
	while(!q.empty())
	{
		int current = q.front();
		q.pop();
		
		if(current+1 == obj) return visit[current]+1;  
		if(current-1 == obj) return visit[current]+1;  
		if(current%2==0 && current/2 == obj) return visit[current]+1;  
		
		if( current+1< 100001 && visit[current+1]==-1)
		{
			visit[current+1] = visit[current]+1;
			q.push(current+1);
		}
		
		if(current>0 && visit[current-1]==-1)
		{
			visit[current-1] = visit[current]+1;
			q.push(current-1);
		}
		if(current!=0&& current%2==0 &&visit[current/2] == -1)
		{
			visit[current/2] = visit[current]+1;
			q.push(current/2);
		}
	}
	
}

int main()
{
	memset(visit,-1,sizeof(int)*100001);
	int s,b;
	
	scanf("%d%d",&s,&b);
	printf("%d\n",find(b,s));
	
	return 0;
}
