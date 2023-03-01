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
char g[N][N];
bool col[N], row[N], dg[N], udg[N];
int n;

void dfs(int x, int y, int s) {

	if (y == n) {
		x ++ ;
		y = 0;
	}

	if (x == n) {
		if (s == n) {
			for (int i = 0; i < n; i ++ ) {
				for (int j = 0; j < n; j ++ ) {
					cout << g[i][j];
				}
				cout << endl;
			}
			cout << endl;
		}
		return ;
	}

	dfs(x, y + 1, s);


	if (!col[x] && !row[y] && !dg[x + y] && !udg[y - x + n]) {
		g[x][y] = 'Q';
		col[x] = row[y] = dg[x + y] = udg[y - x + n] = true;
		dfs(x, y + 1, s + 1);
		col[x] = row[y] = dg[x + y] = udg[y - x + n] = false;
		g[x][y] = '.';
	}

}

void solve()
{
	cin >> n;
	for (int i = 0; i < n; i ++ ) {
		for (int j = 0; j < n; j ++ ) {
			g[i][j] = '.';
		}
	}

	dfs(0, 0, 0);
}

int main()
{
    IOS;
    int t = 1;
    while(t -- )
        solve();

    return 0;
}
