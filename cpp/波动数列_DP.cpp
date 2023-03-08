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
#define IOS ios::sync_with_stdio(false); \
            cin.tie(0);              \
            cout.tie(0);
using namespace std;

typedef long long LL;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;
const int INF = 0x3f3f3f3f;
const LL INFL = 0x3f3f3f3f3f3f3f3f;

const int N = 1010, mod = 100000007;
int dp[N][N];

int get_mod(int a, int b) {
	return (a % b + b) % b;
}

void solve()
{
	int n, s, a, b;
	cin >> n >> s >> a >> b;

	dp[0][0] = 1;
	for (int i = 1; i < n; i ++ ) {
		for (int j = 0; j < n; j ++ ) {
			dp[i][j] = (dp[i - 1][get_mod((j - a * i), n)] + dp[i - 1][get_mod((j + b * i), n)]) % mod;
		}
	}

	cout << dp[n - 1][get_mod(s, n)] << endl;

}

int main()
{
    IOS;
    int t = 1;
    while(t -- )
        solve();

    return 0;
}
