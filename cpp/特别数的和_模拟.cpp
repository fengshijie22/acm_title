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

bool pd(int x) {
	while (x) {
		int t = x % 10;
		if (t == 2 || t == 0 || t == 1 || t == 9) {
			return true;
		}
		x /= 10;
	}
	return false;
}

void solve()
{
	int n, ans = 0;
	cin >> n;
	for (int i = 1; i <= n; i ++ ) {
		if (pd(i)) {
			ans += i;
		}
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
