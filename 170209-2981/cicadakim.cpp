/*
어차피 입력중 하나라도 조건(m으로 나눴을때 같은 나머지)에 해당하지 않으면 안되는 문제이기때문에
오히려 가장 일반적인 경우(제일큰수-제일작은수했을때 나오는 수의 약수들)로 답의 가지수를 좁힌다음에
이를 하나씩 검사하는 방식으로 시간을 줄인게 포인트인듯
*/
#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
using namespace std;

int main()
{
	int N;
	cin >> N;
	vector<int> arr(N);
	for (int i = 0; i<N; i++)
	{
		int item;
		cin >> item;
		arr[i] = item;
	}
	sort(arr.begin(), arr.end());

	int max = arr[arr.size() - 1] - arr[0];
	int bound = sqrt(max);
	vector<int> divided;
	divided.push_back(max);
	for (int m = 2; m <=bound; m++)
	{
		if (max%m != 0)continue;
		divided.push_back(m);
		if(m!=max/m)divided.push_back(max / m);

	}
	vector<int> result;
	for (int i = 0; i < divided.size(); i++)
	{
		int mod = arr[0] % divided[i];
		int j = 1;
		for(; j < arr.size(); j++)
			if (arr[j] % divided[i] != mod)break;
		if (j == arr.size())result.push_back(divided[i]);
	}

	sort(result.begin(), result.end());

	for (int i = 0; i < result.size(); i++)
		cout << result[i] << " ";
	cout << endl;
	return 0;
}
