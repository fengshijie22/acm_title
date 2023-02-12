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
	LL n, m;
	cin >> n >> m;
	if(n == m)
	{
		cout << n << endl;
		return ;
	}
	
	if(min(n, m) == 2 && max(n, m) == 3)
	{
		cout << 3 << endl;
		return ;
	}
	
	cout << min(n, m) << endl;	
}

int main()
{
	IOS;
	int t = 1;
	while(t -- )
		solve();
		
	return 0;
}

