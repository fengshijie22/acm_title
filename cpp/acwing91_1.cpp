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

int a[10], idx;

void solve()
{
	memset(a, 0, sizeof a);
	idx = 0;
	int n;
	cin >> n;
	while(n) {
	 	int x = n % 10;
	 	a[++ idx ] = x;
	 	n /= 10;
	 }

	 int res = 0;
	 for (int i = 1; i <= idx; i ++ ) {
	 	if (a[i] != 0) {
	 		res ++ ;
	 	}
	 }

	 cout << res << endl;
	 for (int i = 1; i <= idx; i ++ ) {
	 	if (a[i] != 0) {
	 		cout << a[i] * pow(10, i - 1) << " ";
	 	}
	 }
	 cout << endl;
}

int main()
{
    IOS;
    int t = 1;
    cin >> t;
    while(t -- )
        solve();

    return 0;
}
