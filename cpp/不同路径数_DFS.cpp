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

const int N = 1e6 + 10;
bool st[N];
int g[6][6];
int n, m, k, res = 0;

void dfs(int x, int y, int u, int ans) {
	if (u > k) {
		if (!st[ans]) {
			res ++ ;
			st[ans] = true;
		}
		return ;
	}

	int dx[4] = {0, -1, 0, 1}, dy[4] = {-1, 0, 1, 0};
	for (int i = 0; i < 4; i ++ ) {
		int d_x = x + dx[i], d_y = y + dy[i];
		if (d_x >= 1 && d_x <= n && d_y >= 1 && d_y <= m) {
			dfs(d_x, d_y, u + 1, ans * 10 + g[d_x][d_y]);
		}
	}
}

void solve()
{
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i ++ ) {
		for (int j = 1; j <= m; j ++ ) {
			cin >> g[i][j];
		}
	}

	for (int i = 1; i <= n; i ++ ) {
		for (int j = 1; j <= m; j ++ ) {
			dfs(i, j, 1, g[i][j]);
		}
	}

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
