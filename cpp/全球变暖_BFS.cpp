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

const int N = 1010;
char g[N][N];
bool st[N][N];
int n;

int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, -1, 0, 1};

bool bfs(int x, int y) {
	queue<PII> q;
	q.push({x, y});
	st[x][y] = true;
	int res = 0;
	while (q.size()) {
		auto t = q.front();
		q.pop();
		bool pd = false;
		for (int i = 0; i < 4; i ++ ) {
			int d_x = dx[i] + t.first, d_y = dy[i] + t.second;
			if (d_x > 1 && d_x < n && d_y > 1 && d_y < n && g[d_x][d_y] == '#' && st[d_x][d_y] == false) {
				q.push({d_x, d_y});
				st[d_x][d_y] = true;
			} 
			if (g[d_x][d_y] == '.') {
				pd = true;
			}
		}
		if (!pd) {
			res ++ ;
		}
	}
	return res;
}

void solve()
{
	cin >> n;
	for (int i = 1; i <= n; i ++ ) {
		for (int j = 1; j <= n; j ++ ) {
			cin >> g[i][j];
		}
	}
	int ans_1 = 0, ans_2 = 0;
	for (int i = 2; i < n; i ++ ) {
		for (int j = 2; j < n; j ++ ) {
			if (g[i][j] == '#' && st[i][j] == false) {
				ans_1 ++ ;
				if (bfs(i, j)) {
					ans_2 ++ ;
				}
			}
		}
	}

	cout << ans_1 - ans_2 << endl;
	

}

int main()
{
    IOS;
    int t = 1;
    while(t -- )
        solve();

    return 0;
}
