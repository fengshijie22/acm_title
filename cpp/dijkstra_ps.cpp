#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 510;
int g[N][N], dist[N], n, m;
bool st[N];

int dijkstra()
{
	memset(dist, 0x3f, sizeof dist);
	dist[1] = 0;
	for(int i = 1; i <= n; i ++ )
	{
		int t = -1;
		for(int j = 1; j <= n; j ++ )
		{
			if(!st[j] && (t == -1 || dist[j] < dist[t]))
				t = j;
		}
		st[t] = true;
		for(int j = 1; j <= n; j ++ )
		{
			dist[j] = min(dist[j], dist[t] + g[t][j]);
		}
	}
	
	if(dist[n] == 0x3f3f3f3f) return -1;
	return dist[n];
	
}

void solve()
{
	memset(g, 0x3f, sizeof g);
	cin >> n >> m;
	for(int i = 1; i <= m; i ++ )
	{
		int x, y, c;
		cin >> x >> y >> c;
		g[x][y] = min(g[x][y], c);
	}
	
	cout << dijkstra() << endl;
	
}

int main()
{
	int t = 1;
	while(t -- )
		solve();
	
	return 0;
}
