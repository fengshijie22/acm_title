#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;

typedef pair<int, int> PII;
const int N = 1e6 + 10;
int h[N], e[N], w[N], ne[N], idx = 0;
bool st[N];
int dist[N], n, m;

void add(int x, int y, int c)
{
	e[idx] = y, w[idx] = c, ne[idx] = h[x], h[x] = idx ++ ;
}

int dijkstra()
{
	memset(dist, 0x3f, sizeof dist);
	dist[1] = 0;
	priority_queue<PII, vector<PII>, greater<PII>> heap;
	heap.push({0, 1});
	
	while(!heap.empty())
	{
		PII t = heap.top();
		heap.pop();
		
		int ver = t.second, dis = t.first;
		if(st[ver]) continue;
		st[ver] = true;
		
		for(int i = h[ver]; i != -1; i = ne[i])
		{
			int j = e[i];
			if(dist[j] > dis + w[i])
			{
				dist[j] = dis + w[i];
				heap.push({dist[j], j});
			}
		}
	}
	
	if(dist[n] == 0x3f3f3f3f) return -1;
	else return dist[n];
	
}

void solve()
{
	memset(h, -1, sizeof h);
	cin >> n >> m;
	
	for(int i = 1; i <= m; i ++ )
	{
		int x, y, c;
		cin >> x >> y >> c;
		add(x, y, c);
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
