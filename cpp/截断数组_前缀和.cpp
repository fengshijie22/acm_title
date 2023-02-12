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
LL a[N], sum[N], st[N], sm[N];

void solve()
{
	int n;
	LL ans = 0;
	cin >> n;
	for(int i = 1; i <= n; i ++ ) {
		cin >> a[i];
		ans += a[i];
	}

	if(ans % 3 != 0) {
		cout << 0 << endl;
		return ;
	}

	LL res1 = ans / 3, res2 = res1 * 2;
	LL res = 0, cnt = 0;
	for(int i = 1; i < n; i ++ ) {
		sum[i] = sum[i - 1] + a[i];
		if(sum[i] == res2) res += cnt;
		if(sum[i] == res1) cnt ++ ;
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
