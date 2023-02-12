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

const int N = 210, INF = 0x3f3f3f3f;
int d[N][N], n, m, q;

void floyd()
{
	for(int k = 1; k <= n; k ++ )
	{
		for(int i = 1; i <= n; i ++ )
		{
			for(int j = 1; j <= n; j ++ )
			{
				d[i][j] = min(d[i][j], d[i][k] + d[k][j]); // 从i -> k更新到i -> j 根据dp 
			}
		}
	}
}

void solve()
{
	cin >> n >> m >> q;
	
	for(int i = 1; i <= n; i ++ )
		for(int j = 1; j <= n; j ++ )
			if(i == j) d[i][j] = 0; // 自环的最短路为0 
			else d[i][j] = INF;
	
	for(int i = 1; i <= m; i ++ )
	{
		int a, b, c;
		cin >> a >> b >> c;
		d[a][b] = min(d[a][b], c); // 邻接矩阵存边 
	}
	
	floyd();
	
	while(q -- )
	{
		int x, y;
		cin >> x >> y;
		
		if(d[x][y] > INF / 2) cout << "impossible" << endl; // 存在负权边 
		else cout << d[x][y] << endl;
	}
	
}

int main()
{
	IOS;
	int t = 1;
	while(t -- )
		solve();
		
	return 0;
}

