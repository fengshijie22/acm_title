#include <iostream>
#include <cstdio>
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
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;
const int INF = 0x3f3f3f3f;
const LL INFL = 0x3f3f3f3f3f3f3f3f;

const int N = 110;
int n, m;
int v[N], w[N], s[N], dp[N][N];

void solve()
{
    cin >> n >> m;
    for(int i = 1; i <= n; i ++ ) cin >> v[i] >> w[i] >> s[i];

    for(int i = 1; i <= n; i ++ )
    	for(int j = 0; j <= m; j ++ )
    		for(int k = 0; k <= s[i] && k * v[i] <= j; k ++ )
    			dp[i][j] = max(dp[i][j], dp[i - 1][j - k * v[i]] + k * w[i]);

    cout << dp[n][m] << endl;

}

int main()
{
    IOS;
    int t = 1;
    while(t -- )
        solve();
        
    return 0;
}
