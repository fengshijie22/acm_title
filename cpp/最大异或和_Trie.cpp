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

const int N = 3e6 + 10;
int tr[N][2], idx = 0, cnt[N];
int a[N], x[N];

void add_s(int id) {
	int p = 0;
	for (int i = 30; i >= 0; i -- ) {
		int u = id >> i & 1;
		if (!tr[p][u]) {
			tr[p][u] = ++ idx ;
		}
		p = tr[p][u];
		cnt[p] ++ ;
	}
}

void pop_s(int id) {
	int p = 0;
	for (int i = 30; i >= 0; i -- ) {
		int u = id >> i & 1;
		if (!tr[p][u]) {
			tr[p][u] = ++ idx ;
		}
		p = tr[p][u];
		cnt[p] -- ;
 	}
}

int find_s(int id) {
	int p = 0;
	int res = 0;
	for (int i = 30; i >= 0; i -- ) {
		int u = id >> i & 1;
		if (cnt[tr[p][!u]]) {
			res = res * 2 + !u;
			p = tr[p][!u];
		}
		else {
			res = res * 2 + u;
			p = tr[p][u];
		}
	}
	return res;
}

void solve()
{
	 int n, m;
	 cin >> n >> m;
	 for (int i = 1; i <= n; i ++ ) {
	 	cin >> a[i];
	 	x[i] = x[i - 1] ^ a[i];
	 }

	 int res = 0;
	 add_s(x[0]);
	 for (int i = 1; i <= n; i ++ ) {
	 	if (i - m - 1 >= 0) {
	 		pop_s(x[i - m - 1]);
	 	}
	 	res = max(res, (find_s(x[i]) ^ x[i]));
	 	add_s(x[i]);
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
