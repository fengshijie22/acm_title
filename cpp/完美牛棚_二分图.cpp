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

const int N = 210, M = 1e5 + 10;
int h[N], e[M], ne[M], idx;
int n, m, match[N];
bool st[N];

void add(int a, int b) {
	e[idx] = b, ne[idx] = h[a], h[a] = idx ++ ;
}

bool find(int x) { // 二分图模板
	for (int i = h[x]; i != -1; i = ne[i]) {
		int j = e[i];
		if (!st[j]) {
			st[j] = true;
			if (!match[j] || find(match[j])) {
				match[j] = x;
				return true;
			}
		}
	}
	return false;
}

void solve()
{
	memset(h, -1, sizeof h);
	cin >> n >> m;
	for (int i = 1; i <= n; i ++ ) {
		int s;
		cin >> s;
		for (int j = 1; j <= s; j ++ ) {
			int a;
			cin >> a;
			add(i, a);
		}
	}

	int res = 0;
	for (int i = 1; i <= n; i ++ ) {
		memset(st, false, sizeof st);
		if (find(i)) res ++ ;
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
