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
int a[N][N], b[N][N];

void solve()
{
	 int n, m, q;
	 cin >> n >> m >> q;
	 for (int i = 1; i <= n; i ++ ) {
	 	for (int j = 1; j <= m; j ++ ) {
	 		cin >> a[i][j];
	 	}
	 }

	 while(q -- ) {
	 	int x1, y1, x2, y2, w;
	 	cin >> x1 >> y1 >> x2 >> y2 >> w;
	 	b[x1][y1] += w, b[x2 + 1][y1] -= w;
	 	b[x1][y2 + 1] -= w, b[x2 + 1][y2 + 1] += w; 
	 }

	 for (int i = 1; i <= n; i ++ ) {
	 	for (int j = 1; j <= m; j ++ ) {
	 		b[i][j] = b[i][j] + b[i - 1][j] + b[i][j - 1] - b[i - 1][j - 1];
	 		a[i][j] += b[i][j];
	 		cout << a[i][j] << " ";
	 	}
	 	cout << endl;
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
