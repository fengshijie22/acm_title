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

void solve()
{	
	LL n;
	cin >> n;
	if(n == 2)
	{
		cout << -1 << endl;
		return ;
	}
	LL m = (n + 1) / 2;
	LL l = m, r = n;
	while(l < r)
	{
		LL mid = (l + r + 1) >> 1;
		if(3 * mid - 2 * m <= n)
			l = mid;
		else
			r = mid - 1;
	}
	
	cout << l << endl;
	
	
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

