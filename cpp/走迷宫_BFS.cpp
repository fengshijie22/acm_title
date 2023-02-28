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
int g[N][N], d[N][N];
int n, m;

void bfs() {
	memset(d, -1, sizeof d);
	d[1][1] = 0;
	queue<PII> q;
	q.push({1, 1});

	int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, -1, 0, 1};
	while (q.size()) {
		auto t = q.front();
		q.pop();
		for (int i = 0; i < 4; i ++ ) {
			int x = dx[i] + t.first, y = dy[i] + t.second;
			if (x >= 1 && x <= n && y >= 1 && y <= m && g[x][y] == 0 && d[x][y] == -1) {
				d[x][y] = d[t.first][t.second] + 1;
				q.push({x, y});
			}
		}
	}

	cout << d[n][m] << endl;

}

void solve()
{
	 cin >> n >> m;
	 for (int i = 1; i <= n; i ++ ) {
	 	for (int j = 1; j <= m; j ++ ) {
	 		cin >> g[i][j];
	 	}
	 }

	 bfs();

}

int main()
{
    IOS;
    int t = 1;
    while(t -- )
        solve();

    return 0;
}