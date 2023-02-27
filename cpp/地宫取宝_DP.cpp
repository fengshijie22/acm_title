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

const int N = 55, mod = 1000000007;
int w[N][N], dp[N][N][13][14];

void solve()
{
	 int n, m, k;
	 cin >> n >> m >> k;
	 for (int i = 1; i <= n; i ++ ) {
	 	for (int j = 1; j <= m; j ++ ) {
	 		cin >> w[i][j];
	 		w[i][j] ++ ;
	 	}
	 }

	 dp[1][1][1][w[1][1]] = 1;
	 dp[1][1][0][0] = 1;

	 for (int i = 1; i <= n; i ++ ) {
	 	for (int j = 1; j <= m; j ++ ) {
	 		if (i == 1 && j == 1) {
	 			continue;
	 		}
	 		for (int u = 0; u <= k; u ++ ) {
	 			for (int v = 0; v < 14; v ++ ) {
	 				int val = dp[i][j][u][v];
	 				val = (val + dp[i - 1][j][u][v]) % mod;
	 				val = (val + dp[i][j - 1][u][v]) % mod;
	 				if (u > 0 && w[i][j] == v) {
	 					for (int c = 0; c < v; c ++ ) {
	 						val = (val + dp[i - 1][j][u - 1][c]) % mod;
	 						val = (val + dp[i][j - 1][u - 1][c]) % mod;
	 					}
	 				}
	 				dp[i][j][u][v] = val;
	 			}
	 		}
	 	}
	 }

	 int res = 0;
	 for (int i = 0; i < 14; i ++ ) {
	 	res = (res + dp[n][m][k][i]) % mod;
	 }

	 cout << res << endl;

}

int main()
{
    IOS
    int t = 1;
    while(t -- )
        solve();

    return 0;
}
