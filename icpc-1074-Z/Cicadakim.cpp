#include <iostream>
#include <math.h>
using namespace std;

long long visitOrder(int N,int r,int c)
{	
	if(N==0) // base
		return 0;
		
	int halfWidth = pow(2,N-1);
		
	int dimension =0;
	if(halfWidth <=r && halfWidth <=c) dimension = 3;
	else if(halfWidth<=r)dimension = 2;
	else if(halfWidth<=c)dimension = 1;
		
	return dimension*pow(halfWidth,2) + visitOrder(N-1, (r >= halfWidth) ? r-halfWidth : r  , (c >= halfWidth) ? c-halfWidth : c  );
}



int main()
{
    int N,r,c;
  
    while(cin >> N >> r >> c)
        cout<<visitOrder(N,r,c)<<endl;
      
    return 0;
}
