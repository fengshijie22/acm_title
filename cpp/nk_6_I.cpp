#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <queue>
#include <deque>
#define IOS ios::sync_with_stdio(0); \
			cin.tie(0);              \
			cout.tie(0);
using namespace std;

const int INF = 0x3f3f3f3f;
typedef long long LL;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;
typedef pair<int, pair<int, int>> PIII;

const int N = 2e5 + 10;
vector<PIII> v;
int h[N], e[N], w[N], ne[N], idx, cw = 0;
bool st[N];
int dist[N], n, m, cnt = 0;

void add(int a, int b, int w1)
{
	e[idx] = b, w[idx] = w1, ne[idx] = h[a], h[a] = idx ++ ;
}

int dijkstra()
{
	memset(dist, 0x3f, sizeof dist);
	dist[1] = 0;
	priority_queue<PII, vector<PII>, greater<PII>> heap;
	heap.push({0, 1});
	
	bool pd = false;
	while(!heap.empty())
	{
		PII t = heap.top();
		heap.pop();
		
		int ver = t.second, dis = t.first;
		if(st[ver]) continue;
		st[ver] = true;
		
		int cnt1 = 0;
		for(int i = h[ver]; i != -1; i = ne[i])
		{
			int j = e[i];
			cnt1 ++ ;
			if(dist[j] > dis + w[i])
			{
				dist[j] = dis + w[i];
				heap.push({dist[j], j});
			}
		}
		if(cnt1 > 1) pd = true;
	}
	
	//return dist[n];
	if(pd) return dist[n];
	else return dist[n] - cw + 1;
	
}

void solve()
{
	memset(h, -1, sizeof h);
	cin >> n >> m;
	for(int i = 1; i <= m; i ++ )
	{
		int a, b, w1;
		cin >> a >> b >> w1;
		if(a == 1 || b == 1) cnt ++ ;
		if(a == b)
		{
			cnt ++ ;
			continue;
		}
		v.push_back({w1, {a, b}});
	}
	for(auto it : v)
	{
		int a = it.second.first, b = it.second.second, w1 = it.first;
		if(cnt > 1)
		{
			add(a, b, 1);
			add(b, a, 1); 
		}
		else
		{
			if(a == 1 || b == 1)
			{
				add(a, b, w1);
				add(b, a, w1);
				cw = w1;
			}
			else
			{
				add(a, b, 1);
				add(b, a, 1);
			}
		}
	}
	
	cout << dijkstra() << endl;
	
}

int main()
{
	IOS;
	int t = 1;
	while(t -- )
		solve();
		
	return 0;
}

