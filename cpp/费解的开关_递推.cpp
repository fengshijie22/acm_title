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

char ma[7][7], back_ma[7][7];
int dx[5] = {-1, 0, 1, 0, 0}, dy[5] = {0, -1, 0, 1, 0};

void tool(int x, int y) {
	for (int i = 0; i < 5; i ++ ) {
		int tx = x + dx[i], ty = y + dy[i];
		if (tx >= 1 && tx <= 5 && ty >= 1 && ty <= 5) {
			if (ma[tx][ty] == '0') ma[tx][ty] = '1';
			else ma[tx][ty] = '0';
		}
	}
}

void solve()
{
	int ans = INF;
	memset(ma, 0, sizeof ma);
	for (int i = 1; i <= 5; i ++ ) {
		for (int j = 1; j <= 5; j ++ ) {
			cin >> ma[i][j];
		}
	}

	for (int i = 0; i <= (1 << 5); i ++ ) {
		int res = 0;
		memcpy(back_ma, ma, sizeof ma);
		for (int j = 0; j < 5; j ++ ) {
			if (i >> j & 1) {
				res ++ ;
				tool(1, j + 1);
			}
		}

		for (int j = 1; j <= 4; j ++ ) {
			for (int k = 1; k <= 5; k ++ ) {
				if (ma[j][k] == '0') {
					res ++ ;
					tool(j + 1, k);
				}
			}
		}

		bool pd = true;
		for (int j = 1; j <= 5; j ++ ) {
			if (ma[5][j] == '0') {
				pd = false;
				break;
			}
		}

		if (pd) {
			ans = min(ans, res);
		}
		memcpy (ma, back_ma, sizeof ma);
	}

	if (ans > 6) {
		cout << -1 << endl;
	}
	else {
		cout << ans << endl;
	}


}

int main()
{
    IOS;
    int t = 1;
    cin >> t;
    while(t -- )
        solve();

    return 0;
}
