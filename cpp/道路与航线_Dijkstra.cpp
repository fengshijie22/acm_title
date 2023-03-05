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

const int N = 2e5 + 10;
int h[N], e[N], ne[N], w[N], idx;
int n, m, k, t, dist[N], ti[N], us[N];
bool st[N];

void add(int a, int b, int c) {
	e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx ++ ;
}

int spfa() {
	memset(dist, 0x3f, sizeof dist);
	queue<int> q;
	for (int i = 1; i <= m; i ++ ) {
		q.push(us[i]);
		dist[us[i]] = 0;
		st[us[i]] = true;
	}

	while (q.size()) {
		int c = q.front();
		q.pop();

		st[c] = false;
		for (int i = h[c]; i != -1; i = ne[i]) {
			int x = e[i];
			if (dist[x] > max(dist[c], dist[w[i]]) + max(ti[c], ti[w[i]])) {
				dist[x] = max(dist[c], dist[w[i]]) + max(ti[c], ti[w[i]]);
				if (!st[x]) {
					q.push(x);
					st[x] = true;
				}
			}
		}
	}

	return dist[t];

}

void solve()
{
	memset(h, -1, sizeof h);
	cin >> n >> m >> k >> t;
	for (int i = 1; i <= n; i ++ ) {
		cin >> ti[i];
	}
	for (int i = 1; i <= m; i ++ ) {
		cin >> us[i];
	}
	while (k -- ) {
		int a, b, c;
		cin >> a >> b >> c;
		add(a, c, b);
		add(b, c, a);
	}

	cout << spfa() << endl;

}

int main()
{
    IOS;
    int t = 1;
    while(t -- )
        solve();

    return 0;
}
