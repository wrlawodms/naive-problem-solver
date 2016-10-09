#include <iostream>
using namespace std;

int main()
{
	int T;
	cin>>T;
	
	for(int t=0; t<T; t++)
	{
		int N;
		cin>>N;
		int* arr = new int[N];
		long long profitSum=0;
		
		for(int n=0; n<N; n++)
			cin>>arr[n];
		
		int currentMax = arr[N-1];
		
		for(int i=N-2; i>=0; i--)
		{
			int current = arr[i];
			if(current > currentMax)
				currentMax = current;
			else
			{
				profitSum += (currentMax - current);
			}
				
		}	
		cout<<profitSum<<endl;	
		
		delete []arr;
	}
	return 0;
}
