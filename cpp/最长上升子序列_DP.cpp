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

const int N = 1010;
int x[N], dp[N], idx = 0;

void solve()
{
	 int n;
	 cin >> n;
	 for (int i = 1; i <= n; i ++ ) {
	 	cin >> x[i];
	 }

	 dp[0] = -INF;
	 for (int i = 1; i <= n; i ++ ) {
	 	if (x[i] > dp[idx]) {
	 		dp[++ idx ] = x[i];
	 	}
	 	else {
	 		int l = 1, r = idx;
	 		while (l < r) {
	 			int mid = (l + r) >> 1;
	 			if (dp[mid] >= x[i]) {
	 				r = mid;
	 			}
	 			else {
	 				l = mid + 1;
	 			}
	 		}
	 		dp[l] = x[i];
	 	}
	 }

	 cout << idx << endl;

}

int main()
{
    IOS;
    int t = 1;
    while(t -- )
        solve();

    return 0;
}
