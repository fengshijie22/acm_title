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

const int N = 520;
int n;
int a[N][N], dp[N][N];

void solve()
{
    cin >> n;
    for(int i = 1; i <= n; i ++ )
    	for(int j = 1; j <= i; j ++ )
    		cin >> a[i][j];

    for(int i = 1; i <= n; i ++ )
    	for(int j = 0; j <= i + 1; j ++ )
    		dp[i][j] = -INF;

    dp[1][1] = a[1][1];
    for(int i = 1; i <= n; i ++ )
    	for(int j = 1; j <= i; j ++ )
    		dp[i][j] = max(dp[i - 1][j - 1], dp[i - 1][j]) + a[i][j];

    int res = -INF;
    for(int i = 1; i <= n; i ++ )
    	res = max(res, dp[n][i]);

    cout << res << endl;

}

int main()
{
    IOS;
    int t = 1;
    while(t -- )
        solve();
        
    return 0;
}
