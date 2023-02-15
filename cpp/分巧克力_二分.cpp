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
int h[N], w[N];
int n, k;

bool check(int mid) {
	int res = 0;
	for (int i = 1; i <= n; i ++ ) {
		res += (h[i] / mid) * (w[i] / mid);
		if(res >= k) return true;
	}
	return false;
}

void solve()
{
	 cin >> n >> k;
	 for (int i = 1; i <= n; i ++ ) {
	 	cin >> h[i] >> w[i];
	 }

	 int l = 1, r = 100000;
	 while (l < r) {
	 	int mid = (l + r + 1) >> 1;
	 	if(check(mid)) l = mid;
	 	else r = mid - 1;
	 }

	 cout << l << endl;

}

int main()
{
    IOS;
    int t = 1;
    while(t -- )
        solve();

    return 0;
}
