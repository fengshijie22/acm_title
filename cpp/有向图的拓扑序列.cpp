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

const int N = 1e5 + 10;
int h[N], e[N], ne[N], idx;
int q[N], d[N];
int n, m;

void add(int a, int b) {
	e[idx] = b, ne[idx] = h[a], h[a] = idx ++ ;
}

bool topsort() {
	int hh = 0, tt = -1;
	for (int i = 1; i <= n; i ++ ) {
		if (!d[i]) {
			q[++ tt ] = i;
		}
	}

	while (hh <= tt) {
		int t = q[hh ++ ];
		for (int i = h[t]; i != -1; i = ne[i]) {
			int x = e[i];
			d[x] -- ;
			if (d[x] == 0) {
				q[++ tt ] = x;
			}
		}
	}

	if (tt == n - 1) {
		return true;
	}
	else {
		return false;
	}

}

void solve()
{
	cin >> n >> m;
	memset(h, -1, sizeof h);
	while (m -- ) {
		int a, b;
		cin >> a >> b;
		add(a, b);
		d[b] ++ ;
	}

	if (topsort()) {
		for (int i = 0; i < n; i ++ ) {
			cout << q[i] << " ";
		}
		cout << endl;
	}
	else {
		cout << -1 << endl;
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
