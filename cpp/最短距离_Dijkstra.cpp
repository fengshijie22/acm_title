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

const int N = 1e5 + 10, M = 3e5 + 10;;
int h[N], e[M], w[M], ne[M], idx;
int dist[N], n, m, k, q;
bool st[N];

void add(int a, int b, int c) {
	e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx ++ ;
}

void dijkstra() {
	memset(dist, 0x3f, sizeof dist);
	dist[0] = 0;

	priority_queue<PII, vector<PII>, greater<PII>> q;
	q.push({0, 0});

	while (q.size()) {
		PII t = q.top();
		q.pop();
		int d = t.first, p = t.second;
		for (int i = h[p]; i != -1; i = ne[i]) {
			int x = e[i];
			if (dist[x] > d + w[i]) {
				dist[x] = d + w[i];
				q.push({dist[x], x});
			}
		}
	}

}

void solve()
{
	memset(h, -1, sizeof h);
	cin >> n >> m;
	for (int i = 1; i <= m; i ++ ) {
		int  a, b, c;
		cin >> a >> b >> c;
		add(a, b, c);
		add(b, a, c);
	}

	cin >> k;
	for (int i = 1; i <= k; i ++ ) {
		int x;
		cin >> x;
		add(0, x, 0);
	}

	dijkstra();

	cin >> q;
	while (q -- ) {
		int x;
		cin >> x;
		cout << dist[x] << endl;
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
