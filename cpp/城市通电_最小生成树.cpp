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

const int N = 2010;
PLL p[N];
LL wk[N], wc[N], fa[N];
LL dist[N];
bool st[N];
vector<LL> ans1;
vector<PLL> ans2;
LL n;

LL get_dist(LL a, LL b) {
	LL dx = abs(p[a].first - p[b].first);
	LL dy = abs(p[a].second - p[b].second);
	return (dx + dy) * (wk[a] + wk[b]);
}

LL prim() {
	memset(dist, 0x3f, sizeof dist);
	dist[0] = 0;
	st[0] = true;

	for (int i = 1; i <= n; i ++ ) {
		dist[i] = wc[i];
	}

	LL res = 0;
	for (int i = 0; i < n; i ++ ) {
		int t = -1;
		for (int j = 1; j <= n; j ++ ) {
			if (!st[j] && (t == -1 || dist[t] > dist[j])) {
				t = j;
			}
		}

		res += dist[t];
		st[t] = true;
		if (!fa[t]) ans1.push_back(t);
		else ans2.push_back({fa[t], t});
		for (int j = 1; j <= n; j ++ ) {
			if (dist[j] > get_dist(t, j)) {
				dist[j] = get_dist(t, j);
				fa[j] = t;
			}
		}
	}

	return res;

}

void solve()
{
	cin >> n;
	for (int i = 1; i <= n; i ++ ) {
		cin >> p[i].first >> p[i].second;
	}
	for (int i = 1; i <= n; i ++ ) {
		cin >> wc[i];
	}
	for (int i = 1; i <= n; i ++ ) {
		cin >> wk[i];
	}

	cout << prim() << endl;
	cout << ans1.size() << endl;
	for (auto it : ans1) {
		cout << it << " ";
	}
	cout << endl;
	cout << ans2.size() << endl;
	for (auto it : ans2) {
		cout << it.first << " " << it.second << endl;
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
