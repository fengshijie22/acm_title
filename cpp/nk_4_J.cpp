#include <iostream>
#include <cstring>
#include <algorithm>
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

const int N = 1e3 + 10;
int ans[N], n, m;
int h1[N], e1[N], ne1[N], idx1;
int h2[N], e2[N], ne2[N], idx2;
bool st[N];

void add1(int a, int b)
{
	e1[idx1] = b, ne1[idx1] = h1[a], h1[a] = idx1 ++ ;
}

void add2(int a, int b)
{
	e2[idx2] = b, ne2[idx2] = h2[a], h2[a] = idx2 ++ ;
}

void dfs(int id, int h[], int e[], int ne[], int &cnt, bool pd)
{
	if(st[id])
		return ;
	if(pd)
	{
		cnt ++ ;
		st[id] = true;
	}
	for(int i = h[id]; i != -1; i = ne[i])
	{
		int j = e[i];
		dfs(j, h, e, ne, cnt, true);
	}
}

int get(int id)
{
	memset(st, false, sizeof st);
	int cntl = 0, cntr = 0;
	dfs(id, h1, e1, ne1, cntl, false);
	dfs(id, h2, e2, ne2, cntr, false);
	return cntl + cntr + 1 == n ? cntr + 1 : 0;
}

void solve()
{
	memset(ans, -1, sizeof ans);
	memset(h1, -1, sizeof h1);
	memset(h2, -1, sizeof h2);
	cin >> n >> m;
	for(int i = 1; i <= m; i ++ )
	{
		int v, u;
		cin >> v >> u;
		add1(v, u);
		add2(u, v);
	}
	for(int i = 1; i <= n; i ++ )
		ans[get(i)] = i;
	for(int i = 1; i <= n; i ++ )
		cout << ans[i] << " ";
	cout << endl;
}

int main()
{
	IOS;
	int t = 1;
	while(t -- )
		solve();
		
	return 0;
}

