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

const int N = 110;
int g[N][N], st[N], a[N];

void solve()
{
	memset(g, 0, sizeof g);
	memset(st, 0, sizeof st);
	memset(a, 0, sizeof a);
	int n;
	cin >> n;
	for(int i = 1; i <= n; i ++ )
	{
		for(int j = 1; j < n; j ++ )
		{
			int x;
			cin >> x;
			g[j][i] = x;
		}
	}
	
	for(int i = 1; i <= n; i ++ )
	{
		st[g[1][i]] ++ ;
	}

	int x = 1;
	for(int i = 1; i <= n; i ++ )
	{
		if(st[i] == n - 1)
		{
			a[1] = i;
		}
		if(st[i] == 1)
			x = i;
	}
	
	for(int i = 2; i <= n; i ++ )
	{
		a[i] = x;
		for(int j = 1; j < n; j ++ )
		{
			if(g[i][j] != x)
			{
				x = g[i][j];
				break;
			}
		}
	}
	
	for(int i = 1; i <= n; i ++ )
		cout << a[i] << " ";
	cout << endl;
}

int main()
{
	IOS;
	int t = 1;
	cin >> t;
	while(t -- )
		solve();
		
	return 0;
}

