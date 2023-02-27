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

const int N = 1e5 + 10, M = 31 * N;
int ma[M][2],a[N], idx;

void add_s(int x) {
	int p = 0;
	for (int i = 30; i >= 0; i -- ) {
		int u = x >> i & 1;
		if (!ma[p][u]) {
			ma[p][u] = ++ idx;
		}
		p = ma[p][u];
	}

}

int find_s(int x) {
	int p = 0, res = 0;
	for (int i = 30; i >= 0; i -- ) {
		int u = x >> i & 1;
		if (ma[p][!u]) {
			p = ma[p][!u];
			res = res * 2 + !u;
		}
		else {
			p = ma[p][u];
			res = res * 2 + u;
		}
	}

	return res;
}

void solve()
{
	 int n;
	 cin >> n;
	 for (int i = 1; i <= n; i ++ ) {
	 	cin >> a[i];
	 }

	 int res = 0;
	 for (int i = 1; i <= n; i ++ ) {
	 	add_s(a[i]);
	 	int t = find_s(a[i]);
	 	res = max(res, (a[i] ^ t));
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
