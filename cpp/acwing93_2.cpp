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

LL n, ans = INFL;

void dfs(LL x, LL d) {
	LL cnt = 0;
	LL y = x;
	bool st[10] = {0};
	while (y) {
		int t = y % 10;
		st[t] = true;
		cnt ++ ;
		y /= 10;
	}

	if (d + n - cnt >= ans) {
		return ;
	}
	if (cnt == n) {
		ans = min(ans, d);
		return ;
	}

	for (int i = 9; i >= 2; i -- ) {
		if (st[i] == true) {
			dfs(x * i, d + 1);
		}
	}

}

void solve()
{
	LL x;
	cin >> n >> x;

	dfs(x, 0);

	if (ans == INFL) ans = -1;
	cout << ans << endl;

}

int main()
{
    IOS;
    int t = 1;
    while(t -- )
        solve();

    return 0;
}
