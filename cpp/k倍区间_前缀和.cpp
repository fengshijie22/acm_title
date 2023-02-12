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
LL a[N], sum[N], res[N] = {1};

void solve()
{
    int n, k;
    cin >> n >> k;
    for(int i = 1; i <= n; i ++ ) {
    	cin >> a[i];
    	sum[i] = (sum[i - 1] + a[i]) % k;
    	res[sum[i]] ++ ;
    }

    LL ans = 0;
    for(int i = 0; i < k; i ++ ) {
    	ans += (res[i] * (res[i] - 1) / 2);
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
