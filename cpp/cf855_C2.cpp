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

LL a[200010];

void solve()
{
	memset(a, 0, sizeof a);
	LL n;
	cin >> n;
	for (LL i = 1; i <= n; i ++ ) {
		cin >> a[i];
	}

	LL res = 0;
	priority_queue<LL> q;
	for (LL i = 1; i <= n; i ++ ) {
		if (a[i] == 0) {
			if (q.size()) {
				res += q.top();
				q.pop();
			}
		}
		else {
			q.push(a[i]);
		}
	}

	cout << res << endl;

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
