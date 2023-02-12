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
int a[N][N], sum[N][N];

void solve()
{
    int n, m, k;
    cin >> n >> m >> k;

    for (int i = 1; i <= n; i ++ ) {
    	for (int j = 1; j <= m; j ++ ) {
    		cin >> a[i][j];
    	}
    }

    for (int i = 1; i <= n; i ++ ) {
    	for (int j = 1; j <= m; j ++ ) {
    		sum[i][j] = a[i][j] + sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1];
    	}
    }

    while (k -- ) {
    	int x1, y1, x2, y2;
    	cin >> x1 >> y1 >> x2 >> y2;
    	cout << sum[x2][y2] - sum[x1 - 1][y2] - sum[x2][y1 - 1] + sum[x1 - 1][y1 - 1] << endl;
    }

}

int main()
{
    IOS;
    int t = 1;
    while(t -- )
        solve();
        
    return 0;
}
