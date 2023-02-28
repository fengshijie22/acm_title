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

const int N = 1e4 + 10;
int a[N], b[N];

void solve()
{
	 int n;
	 cin >> n;
	 for (int i = 1; i <= n; i ++ ) {
	 	cin >> a[i];
	 }
	 int ans = 0;
	 for (int i = 1; i <= n; i ++ ) {
	 	int maxx = 0, minn = INF;
	 	for (int j = i; j <= n; j ++ ) {
	 		maxx = max(a[j], maxx);
	 		minn = min(a[j], minn);
	 		if ((maxx - minn) == (j - i)) {
	 			ans ++ ;
	 		}
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
