
// 暴力 o(n ^ 3)

/*

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
LL a[N], dp[N], sum[N];

void solve()
{
	LL n, m, pos = 1, head = 1, tail = 0;
	cin >> n >> m;
	memset(dp, 0x3f, sizeof dp);
	for (int i = 1; i <= n; i ++ ) {
		cin >> a[i];
		if (a[i] > m) {
			cout << "-1" << endl;
			return ;
		}
		sum[i] = sum[i - 1] + a[i];
	} 

	dp[0] = 0;

	// 暴力 TLE
	for (int i = 0; i <= n; i ++ ) {
		for (int j = 0; j <= i; j ++ ) {
			if ((j == 0 && sum[i] <= m) || (j != 0 && sum[i] - sum[j] <= m)) {
				LL maxx = 0;
				for (int k = j + 1; k <= i; k ++ ) {
					maxx = max(maxx, a[k]);
				}
				dp[i] = min(dp[i], dp[j] + maxx);
			}
		}

	}

	cout << dp[n] << endl;
}

int main()
{
    IOS;
    int t = 1;
    while(t -- )
        solve();

    return 0;
}

*/

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

const int N = 1e5 + 10;
LL a[N], q[N], dp[N], head = 1, tail = 0;
multiset<LL> s;

void solve()
{
	 LL n, m;
	 cin >> n >> m;

	 for (int i = 1; i <= n; i ++ ) {
	 	cin >> a[i];
	 	if (a[i] > m) {
	 		cout << "-1" << endl;
	 		return ;
	 	}
	 }

	 LL sum = 0;
	 for (int i = 1, j = 1; i <= n; i ++ ) {
	 	sum += a[i];
	 	while (sum > m) {
	 		sum -= a[j ++ ];
	 		if (head <= tail && q[head] < j) {
	 			if (head < tail) {
	 				auto it = s.find(dp[q[head]] + a[q[head + 1]]);
	 				s.erase(it);
	 			}
	 			head ++ ;
	 		}
	 	}

	 	while (head <= tail && a[q[tail]] <= a[i]) {
	 		if (head < tail) {
	 			auto it = s.find(dp[q[tail - 1]] + a[q[tail]]);
	 			s.erase(it);
	 		}
	 		tail -- ;
	 	}

	 	q[++ tail ] = i;

	 	if (head < tail) s.insert(dp[q[tail - 1]] + a[q[tail]]);

	 	dp[i] = dp[j - 1] + a[q[head]];

	 	if (s.size()) {
	 		dp[i] = min(dp[i], *s.begin());
	 	} 
	 }

	 cout << dp[n] << endl;

}

int main()
{
    IOS;
    int t = 1;
    while(t -- )
        solve();

    return 0;
}

