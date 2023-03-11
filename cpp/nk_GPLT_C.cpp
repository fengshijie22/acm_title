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

const int N = 1e6 + 10;
bool col[N], row[N], dg[N], udg[N];

void solve()
{
	int n, t;
	cin >> n >> t;
	while (t -- ) {
		int l, r;
		cin >> l >> r;
		if (!col[l] && !col[r] && !dg[l + r] && !udg[l - r + n]) {
			cout << "Yes" << endl;
			col[l] = row[r] = dg[l + r] = udg[r - l + n] = true;
		}
		else {
			cout << "No" << endl;
		}
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
