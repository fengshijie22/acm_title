#include <iostream>
#include <cstring>
#include <algorithm>
#define IOS ios::sync_with_stdio(0); \
			cin.tie(0);              \
			cout.tie(0);
using namespace std;

typedef long long LL;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;

const int N = 1e5 + 10;
int h[N], e[N << 1], ne[N << 1], idx = 0, n, m;
int res = 0;

void add(int a, int b)
{
	e[idx] = b, ne[idx] = h[a], h[a] = idx ++ ;
}

int dfs(int u, int head)
{
	int dist = 0, d1 = 0, d2 = 0;
	
	for(int i = h[u]; i != -1; i = ne[i])
	{
		int j = e[i];
		if(j == head) continue;
		
		int d = dfs(j, u) + 1;
		
		dist = max(dist, d);
		if(d >= d1) d2 = d1, d1 = d;
		else d2 = d;
		
		res = max(res, d1 + d2);
		
	}
	
	return dist;
	
}

void solve()
{
	memset(h, -1, sizeof h);
	cin >> n >> m;
	for(int i = 1; i <= m; i ++ )
	{
		int a, b;
		cin >> a >> b;
		add(a, b);
		add(b, a);
	}
	
	dfs(1, -1);
	
	cout << res << endl;
	
}

int main()
{
	IOS;
	int t = 1;
	while(t -- )
		solve();
		
	return 0;
}

