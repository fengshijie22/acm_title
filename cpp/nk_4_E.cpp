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
int h[N], v[N], ch[N];

void solve()
{
	int n, t, a;
	cin >> n >> t >> a;
	for(int i = 1; i <= n; i ++ )
	{
		cin >> h[i] >> v[i];
		ch[i] = h[i];
		if(h[i] > a && v[i] * t >= a)
		{
			cout << -1 << endl;
			return ;
		}
	}
	
	int res = 0, i = 1;
	while(i <= n)
	{
		if(h[i] <= a)
		{
			i ++ ;
			res ++ ;
		}
		else
		{
			int cx = a - v[i] * t;
			int x = (h[i] - a + cx - 1) / cx + 1;
			i ++ ;
			res += x;			
		}

	}
	//cout << res << endl;
	cout << 1 + (res - 1) * t << endl;
	
}

int main()
{
	IOS;
	int t = 1;
	while(t -- )
		solve();
		
	return 0;
}

