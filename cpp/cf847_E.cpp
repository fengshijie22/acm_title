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
	LL x; 
	cin >> x;
	LL a = 0;
	for(a = 1; a <= x; a ++ )
	{
		LL b = (x ^ a);
		if(a + b == 2 * x)
		{
			cout << a << " " << b << endl;
			return ;
		}
	}
	cout << -1 << endl;
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

