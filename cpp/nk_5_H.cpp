#include <iostream>
#include <cstring>
#include <algorithm>
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

void solve()
{
	LL x, y, k, n, T;
	cin >> x >> y >> k >> n >> T;
	LL res = 0;
	LL cnt = 0;
	LL c = n;
	while(n -- )
	{
		res += (x * (n + 1));
		x += (((n + 1) / k) * y);
		cnt += ((n + 1) % k);
		while(cnt >= k)
		{
			x += y;
			cnt -= k;
		}
		if(res >= T)
		{
			cout << c - n << endl;
			return ;
		}
	}
	
	if(res < T) cout << -1 << endl;
	
}

int main()
{
	IOS;
	int t = 1;
	while(t -- )
		solve();
		
	return 0;
}

