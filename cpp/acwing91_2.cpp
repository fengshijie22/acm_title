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
int a[N], b[N];

void solve()
{
	 int n, m;
	 cin >> n >> m;
	 for (int i = 1; i <= m; i ++ ) {
	 	int l, r;
	 	cin >> l >> r;
	 	a[l] ++ ;
	 	a[r + 1] -- ;
	 }

	 bool pd = true;
	 for (int i = 1; i <= n; i ++ ) {
	 	b[i] = b[i - 1] + a[i];
	 	if (b[i] > 1 || b[i] == 0) {
	 		cout << i << " " << b[i] << endl;
	 		return ;
	 	}
	 }

	 if (pd) cout << "OK" << endl;

}

int main()
{
    IOS;
    int t = 1;
    while(t -- )
        solve();

    return 0;
}
