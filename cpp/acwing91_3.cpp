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

int n, m;

bool check(vector<vector<int>> &g, int mid) {
	vector<bool> st(m, false);
	vector<int> cnt(n, 0);

	for (int i = 0; i < m; i ++ ) {
		for (int j = 0; j < n; j ++ ) {
			if (g[j][i] >= mid) {
				st[i] = true;
				cnt[j] ++ ;
			}
		}
		if (st[i] == false) {
			return false;
		} 
	}

	if (n < m - 1) {
		return true;
	} 

	for (int i = 0; i < n; i ++ ) {
		if (cnt[i] > 1) return true;
	}
	return false;

}

void solve()
{
	 cin >> n >> m;
	 vector<vector<int>> g(n, vector<int> (m));

	 for (auto &u : g) {
	 	for (auto &v : u) {
	 		cin >> v;
	 	}
	 }

	 int l = 1, r = 1e9;
	 while(l < r) {
	 	int mid = (l + r + 1) >> 1;
	 	if (check(g, mid)) l = mid;
	 	else r = mid - 1;
	 }

	 cout << l << endl;

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
