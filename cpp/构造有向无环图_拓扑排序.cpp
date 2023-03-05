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
            cin.tie(0);                  \
            cout.tie(0);
using namespace std;

typedef long long LL;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;
const int INF = 0x3f3f3f3f;
const LL INFL = 0x3f3f3f3f3f3f3f3f;

const int N = 2e5 + 10;
int h[N], e[N], ne[N], idx;
PII bi[N];
int n, m, id, q[N], d[N];
int pos[N];

void add(int a, int b) {
	e[idx] = b, ne[idx] = h[a], h[a] = idx ++ ;
}

bool topsort() {
	int tt = -1, hh = 0;
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
			if (!d[x]) {
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
	id = 0;
	scanf("%d%d", &n, &m);
	memset(h, -1, (n + 1) * 4);
	memset(d, 0, (n + 1) * 4);
	for (int i = 1; i <= m; i ++ ) {
		int t, a, b;
		scanf("%d%d%d", &t, &a, &b);
		if (t == 0) {
			bi[id ++ ] = {a, b};
		}
		else {
			add(a, b);
			d[b] ++ ;
		}
	}

	if (topsort()) {
		printf("YES\n");
		for (int i = 1; i <= n; i ++ ) {
			for (int j = h[i]; j != -1; j = ne[j]) {
				printf("%d %d\n", i, e[j]);
			}
		}
		for (int i = 0; i < n; i ++ ) {
			pos[q[i]] = i;
		}

		for (int i = 0; i < id; i ++ ) {
			int a = bi[i].first, b = bi[i].second;
			if (pos[a] > pos[b]) {
				swap(a, b);
			}
			printf("%d %d\n", a, b);
		}
	}
	else {
		printf("NO\n");
	}

}

int main()
{
    IOS;
    int t = 1;
    scanf("%d", &t);
    while(t -- )
        solve();

    return 0;
}
