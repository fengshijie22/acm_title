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

void solve()
{
	 LL n, k;
	 cin >> n >> k;
	 if (k == 0) {
	 	LL ans = n * (n - 1) / 2;
	 	cout << ans << endl;
	 	return ;
	 }

	 LL res = 0;
	 for (int i = 1; i <= n; i ++ ) {
	 	LL t = (k + 1) * i;
	 	LL m = k * i;
	 	if (m > n) m = n + 1;
	 	if (t > n) t = n + 1;
	 	LL c = t - m;
	 	res += c;
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
