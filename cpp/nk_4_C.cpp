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

const int N = 5010;
const LL INFL = (1LL << 60);
LL dp[N], v[N];
int w[N], n, m;

LL get(int id)
{
	memset(dp, 0, sizeof dp);
	for(int i = 1; i <= n; i ++ )
	{
		if(id == i) continue;
		for(int j = m; j >= w[i]; j -- )
		{
			dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
		}
	}
	LL lim = dp[m];
	LL ans = INFL;
	for(int j = m - w[id]; j >= 0; j -- )
	{
		ans = min(ans, max(lim - (dp[j] + v[id]) + 1, 0LL));
	}
	
	return ans;
	
}

void solve()
{
	cin >> n >> m;
	for(int i = 1; i <= n; i ++ )
		cin >> w[i] >> v[i];
	
	for(int i = 1; i <= n; i ++ )
		cout << get(i) << endl;
	
}

int main()
{
	IOS;
	int t = 1;
	while(t -- )
		solve();
		
	return 0;
}
