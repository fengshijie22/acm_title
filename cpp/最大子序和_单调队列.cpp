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
const int INFL = 0x3f3f3f3f3f3f3f3f;

const int N = 3e5 + 10;
int a[N], q[N], sum[N], head = 1, tail = 0;

void solve()
{
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i ++ ) {
		cin >> a[i];
		sum[i] = sum[i - 1] + a[i];
	} 

	int ans = -INF;

	q[++ tail] = 0;

	for (int i = 1; i <= n; i ++ ) {
		while (head <= tail && q[head] < i - m) {
			head ++ ;
		}
		ans = max(ans, sum[i] - sum[q[head]]);
		while (head <= tail && sum[q[tail]] >= sum[i]) {
			tail -- ;
		}
		q[++ tail] = i;
	}

	cout << ans << endl;

}

int main()
{
    IOS;
    int t = 1;
    while(t -- )
        solve();

    return 0;
}
