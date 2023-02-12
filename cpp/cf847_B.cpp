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

int a[310];

void solve()
{
	int n, s, r;
	cin >> n >> s >> r;
	int maxx = s - r;
	int c = r / (n - 1), y = r % (n - 1);
	for(int i = 1; i <= n - 1; i ++ )
	{
		a[i] = c;
	}
	a[n] = maxx;
	int i = 1;
	while(y)
	{
		if(c + y <= maxx)
		{
			a[i] = c + y;
			y = 0;
		}
		else
		{
			 a[i ++ ] = maxx;
			 y = y - (maxx - c);
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

