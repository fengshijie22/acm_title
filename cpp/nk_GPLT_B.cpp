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
int z[N], w[N];
vector<PII> v;

bool cmp(PII a, PII b) {
	return a.first > b.first;
}

void solve()
{
	int n, k;
	cin >> n >> k;
	for (int i = 1; i <= n; i ++ ) {
		cin >> z[i] >> w[i];
		v.push_back({w[i] - z[i], i});
	}

	sort(v.begin(), v.end(), cmp);

	LL res = 0;
	for (int i = 0; i < n; i ++ ) {
		if (i < k) {
			res += w[v[i].second];
		}
		else {
			res += z[v[i].second];
		}
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
