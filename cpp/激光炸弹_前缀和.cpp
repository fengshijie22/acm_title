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

const int M = 10010, N = 5010;
int a[M][M];

void solve()
{
    int n, r, x1, y1, w1;
    cin >> n >> r;
    int x, y;
    for(int i = 1; i <= n; i ++ ) {
    	cin >> x1 >> y1 >> w1;
    	a[x1 + 1][y1 + 1] += w1;
    }

    for (int i = 1; i <= N; i ++ ) {
    	for (int j = 1; j <= N; j ++ ) {
    		a[i][j] = a[i][j] + a[i - 1][j] + a[i][j - 1] - a[i - 1][j - 1];
    	}
    }

    int res = 0;
    for (int i = r; i <= N; i ++ ) {
    	for (int j = r; j <= N; j ++ ) {
    		res = max(res, a[i][j] - a[i - r][j] - a[i][j - r] + a[i - r][j - r]);
    	}
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
