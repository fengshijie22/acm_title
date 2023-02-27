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
int a[N][N], dp[N][N];

void solve()
{
	 memset(a, 0, sizeof a);
	 memset(dp, 0, sizeof dp);
	 int n, m;
	 cin >> n >> m;
	 for (int i = 1; i <= n; i ++ ) {
	 	for (int j = 1; j <= m; j ++ ) {
	 		cin >> a[i][j];
	 	}
	 } 

	 for (int i = 1; i <= n; i ++ ) {
	 	for (int j = 1; j <= m; j ++ ) {
	 		dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]) + a[i][j];
	 	}
	 }

	 cout << dp[n][m] << endl;

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
