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
	LL k = n / 13, d = n % 13;
	if(d <= 5) cout << 5 * k + d << endl;
	else cout << 5 * k + 5 << endl;
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

