#include <iostream>
#include <cstring>
#include <algorithm>
#define IOS ios::sync_with_stdio(false); \
			cin.tie(0);              	 \
			cout.tie(0);
using namespace std;

typedef long long LL;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;

const int N = 2e5 + 10;
LL a[N], sum[N], n;

void solve()
{
	cin >> n;
	for(LL i = 1; i <= n; i ++ )
	{
		cin >> a[i];
		sum[i] = a[i] + sum[i - 1];
	}
	
	LL res = 0;
	for(LL i = 1; i < n; i ++ )
	{
		res = max(res, __gcd(sum[i], sum[n] - sum[i]));
	}
	
	cout << res << endl;
	
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

