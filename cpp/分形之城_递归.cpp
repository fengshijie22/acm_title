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

PLL dfs(LL n, LL s) {
	if (n == 0) return {0, 0};
	LL len = pow(2, (n - 1));
	LL cnt = len * len;
	LL cot = s / cnt;
	LL idx = s % cnt;
	PLL pos = dfs(n - 1, idx);

	LL x = pos.first, y = pos.second;
	if (cot == 0) {
		return {y, x};
	}
	if (cot == 1) {
		return {x, y + len};
	}
	if (cot == 2) {
		return {x + len, y + len};
	}
	if (cot == 3) {
		return {len * 2 - y - 1, len - x - 1};
	}

}

LL rounding(double a) {
	LL b;
	if (a > 0) {
		b = (a * 2 + 1) / 2;
	}
	else {
		b = (a * 2 - 1) / 2;
	}
	return b;
}

void solve()
{
	 LL t;
	 cin >> t;
	 while (t -- ) {
	 	LL n, a, b;
	 	cin >> n >> a >> b;
	 	PLL zb1 = dfs(n, a - 1);
	 	PLL zb2 = dfs(n, b - 1);
	 	LL x = (zb1.first - zb2.first);
	 	LL y = (zb1.second - zb2.second);
	 	double dist = sqrt(x * x + y * y) * 10;
	 	cout << rounding(dist) << endl;
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
