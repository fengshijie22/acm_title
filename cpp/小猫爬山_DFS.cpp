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

const int N = 20;
LL cnt[N], c[N];
LL n, w;
int ans;

bool cmp(int a, int b) {
	return a > b;
}

void dfs(int ca, int u) {
	if (u >= ans) {
		return ;
	}
	if (ca == n + 1) {
		ans = min(ans, u);
		return ;
	}

	for (int i = 1; i <= u; i ++ ) {
		if (c[ca] + cnt[i] <= w) {
			cnt[i] += c[ca];
			dfs(ca + 1, u);
			cnt[i] -= c[ca];
		}
	}

	cnt[u + 1] += c[ca];
	dfs(ca + 1, u + 1);
	cnt[u + 1] = 0;

}

void solve()
{
	cin >> n >> w;
	for (int i = 1; i <= n; i ++ ) {
		cin >> c[i];
	}

	sort(c + 1, c + n + 1, cmp);

	ans = n;
	dfs(1, 0);

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
