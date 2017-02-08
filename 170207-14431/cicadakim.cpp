#include <iostream>
#include <vector>
#include <math.h>
#include <queue>
using namespace std;

vector<pair<int, int> > cities;
vector<vector<int> > path;
int length;


bool isPrime(int num)
{
	if (num < 2 || (num & 1) == 0)return false;
	int rootNum = (int)sqrt(num);
	int div = 0;

	for (div = rootNum; div>1; div--)
	{
		if (num%div == 0)return false;
	}
	return true;

}

int dist(int x1, int y1, int x2, int y2)
{
	return sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
}

void makePath(int i, int j)
{
	int d = dist(cities[i].first, cities[i].second, cities[j].first, cities[j].second);

	if (isPrime(d))
	{
		path[i][j] = d;
		path[j][i] = d;
	}

}

int findMinPath(int start, int end)
{
	vector<int> dist = vector<int>(length, -1);
	priority_queue< pair<int, int> > q;
	q.push(make_pair(0, start));
	dist[start] = 0;

	while (!q.empty())
	{
		int here = q.top().second;
		int d = -q.top().first;
		q.pop();
		if (d > dist[here]) continue;

		for (int i = 0; i<length; i++)
		{
			if (path[here][i] <= 0)continue;
			int nextDist = path[here][i] + d;

			if (dist[i] == -1 || nextDist < dist[i])
			{
				dist[i] = nextDist;
				q.push(make_pair(-nextDist, i));
			}
		}
	}

	return dist[end];

}

int main()
{
	int x1, x2, y1, y2;
	cin >> x1 >> y1 >> x2 >> y2;

	int n;
	cin >> n;
	length = n + 2;
	path = vector<vector<int> >(n + 2, vector<int>(n + 2, 0));


	cities.push_back(make_pair(x1, y1));
	cities.push_back(make_pair(x2, y2));
	makePath(0, 1);

	for (int i = 2; i < n + 2; i++)
	{
		int x3, y3;
		cin >> x3 >> y3;
		cities.push_back(make_pair(x3, y3));

		for (int j = 0; j <= i - 1; j++)
			makePath(i, j);
	}
	cout << findMinPath(0, 1) << endl;

	return 0;
}
