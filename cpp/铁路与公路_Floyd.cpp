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

const int N = 410;
int a[N][N], b[N][N];
int n, m;
bool st[N][N];

void floyd(int d[N][N]) {
	for (int k = 1; k <= n; k ++ ) {
		for (int i = 1; i <= n; i ++ ) {
			for (int j = 1; j <= n; j ++ ) {
				d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
			}
		}
	}
}

void solve()
{
	cin >> n >> m;
	for (int i = 1; i <= n; i ++ ) {
		for (int j = 1; j <= n; j ++ ) {
			if (i == j) {
				a[i][j] = 0;
				b[i][j] = 0;
			}
			else {
				a[i][j] = INF;
				b[i][j] = INF;
			}
		}
	}

	while (m -- ) {
		int u, v;
		cin >> u >> v;
		st[u][v] = st[v][u] = true;
		a[u][v] = a[v][u] = min(a[u][v], 1);
	}

	floyd(a);

	if (a[1][n] == INF) {
		cout << "-1" << endl;
		return ;
	}

	for (int i = 1; i <= n; i ++ ) {
		for (int j = 1; j <= n; j ++ ) {
			if (!st[i][j] && !st[j][i]) {
				b[i][j] = min(b[i][j], 1);
			}
		}
	}

	floyd(b);

	if (b[1][n] == INF) {
		cout << "-1" << endl;
	}
	else {
		cout << max(a[1][n], b[1][n]) << endl;
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
