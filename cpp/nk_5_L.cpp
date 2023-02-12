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

typedef long long LL;
const int INF = 0x3f3f3f3f;
const LL INFL = 0x3f3f3f3f3f3f3f3f;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;
//vector<PLL> v;
PLL v[510];
LL dp[100010];

void solve()
{
	memset(dp, 0x3f, sizeof dp);
	int n, m;
	cin >> n >> m;
	//v.push_back({0, 0});
	for(int i = 1; i <= m; i ++ )
	{
		LL w, x;
		cin >> w >> x;
		//v.push_back({w, x});
		v[i] = {w, x};
	}
	
	dp[n] = 0;
	for(int i = n; i > 0; -- i )
	{
		for(int j = 1; j <= m; j ++ )
		{
			PLL c = v[j];
			LL w = c.first, x = c.second;
			if(i < x) continue;
			x = i / x * x;
			dp[x] = min(dp[x], dp[i] + w);
		}
	}
	for(int i = 1; i <= n; i ++ )
	{
		if(dp[i] != INFL)
		{
			cout << dp[i] << endl;
			return ;
		}
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

