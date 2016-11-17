#include <iostream>
#include <vector>
#include <queue>
using namespace std;

bool findST(vector<vector<int> >& arr, int start, int end)
{
	int current = start;
	vector<int> path;
	vector<bool> visited = vector<bool>(end+1 , false);
	bool hasNext;
	while(true)
	{
		hasNext = false;
		visited[current] = true;
		if(current == end)
		{
			path.push_back(current);
			for(int i=path.size()-1; i>=1; i--)
			{
				int to = path[i];
				int fr = path[i-1];	
				arr[fr][to]--;
				arr[to][fr]++;			
			}			
			return true;
		}
		for(int next = start; next<=end; next++)
		{
			if(arr[current][next] == 1  && !visited[next]  )
			{
				path.push_back(current);
				current = next;
				hasNext = true;
				break;
			}
		}
		if(!hasNext)
		{
			if(path.empty())return false;
			current = path[path.size()-1];
			path.pop_back(); 
			
		}
			 
	}
}


int main()
{
	freopen("11375.txt","r",stdin);
	
	int N,M;
	cin>>N>>M;
	
	vector<vector<int> > arr( N+M+2 , vector<int>(N+M+2,0)  );
	
	for(int i=1; i<=N; i++)
		arr[0][i] = 1;
	
	for(int i=N+1; i<=N+M; i++) 
		arr[i][N+M+1] = 1;
	
	for(int i=1; i<=N; i++)
	{
		int numJobs;
		cin>>numJobs;
		for(int j=0; j<numJobs; j++)	
		{
			int job;
			cin>>job;
			 
			arr[i][N + job]=1;
		}
	}
	
	int maxFlow = N;
	while( maxFlow>=0 &&  findST(arr,0,N+M+1) )
		maxFlow--;
	
	cout<<N-maxFlow<<endl;
	
	return 0;
}
