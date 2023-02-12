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

const int N = 110;
int a[N][N], b[N][N];
bool stl[N], str[N];

void solve()
{
	int n, m;
	cin >> n >> m;
	bool pd = false;
	for(int i = 1; i <= n; i ++ )
	{
		for(int j = 1; j <= m; j ++ )
		{
			cin >> b[i][j];
			if(b[i][j] == 0)
				stl[i] = str[j] = true;
		}
	}
	
	for(int i = 1; i <= n; i ++ )
	{
		for(int j = 1; j <= m; j ++ )
		{
			if(b[i][j] == 1)
			{
				if(stl[i] && str[j])
				{
					cout << "NO" << endl;
					return ;
				}
				if(!stl[i] && !str[j])
					a[i][j] = 1;
			}
		}
	}
	
	cout << "YES" << endl;
	for(int i = 1; i <= n; i ++ )
	{
		for(int j = 1; j <= m; j ++ )
			cout << a[i][j] << " ";
		cout << endl;
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

