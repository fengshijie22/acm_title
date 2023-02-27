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

char a[5][5];
vector<PII> t, g;

void tool_one(int x, int y) {
	if (a[x][y] == '+') {
		a[x][y] = '-';
	}
	else {
		a[x][y] = '+';
	}
}

void tool_cr(int x, int y) {
	for (int i = 0; i < 4; i ++ ) {
		tool_one(x, i);
		tool_one(i, y);
	}
	tool_one(x, y);
}

void dfs(int x, int y) {
	if (x == 3 && y == 4) {
		bool pd = false;
		for (int i = 0; i < 4; i ++ ) {
			for (int j = 0; j < 4; j ++ ) {
				if (a[i][j] == '+') {
					pd = true;
					break;
				}
			}
			if (pd) {
				break;
			}
		}

		if (!pd) {
			if (!g.size() || g.size() > t.size()) {
				g = t;
			}
		}

		return ;
	}

	if (y == 4) {
		x ++ , y = 0;
	}

	tool_cr(x, y);
	t.push_back({x, y});
	dfs(x, y + 1);
	t.pop_back();
	tool_cr(x, y);

	dfs(x, y + 1);

}

void solve()
{
	 for (int i = 0; i < 4; i ++ ) {
	 	for (int j = 0; j < 4; j ++ ) {
	 		cin >> a[i][j];
	 	}
	 }

	 dfs(0, 0);

	 cout << g.size() << endl;
	 for (auto item : g) {
	 	cout << item.first + 1 << " " << item.second + 1 << endl;
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
