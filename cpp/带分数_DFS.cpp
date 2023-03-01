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

const int N = 10;
int t[N];
bool st[N];
int n, ans = 0;

int check(int l, int r) {
	int res = 0;
	for (int i = l; i <= r; i ++ ) {
		res = res * 10 + t[i];
	}
	return res;
}

void dfs(int u) {
	if (u == 10) {
		for (int i = 1; i <= 7; i ++ ) {
			for (int j = i + 1; j <= 8; j ++ ) {
				int x = check(1, i);
				int y = check(i + 1, j);
				int z = check(j + 1, 9);
				if (x * z + y == z * n) {
					ans ++ ;
				}
			}
		}
		return ;
	}

	for (int i = 1; i <= 9; i ++ ) {
		if (!st[i]) {
			t[u] = i;
			st[i] = true;
			dfs(u + 1);
			st[i] = false;
			t[u] = 0;
		}
	}

}

void solve()
{
	cin >> n;
	dfs(1);

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
