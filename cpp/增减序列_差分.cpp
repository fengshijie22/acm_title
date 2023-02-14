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
LL a[N];

void solve()
{
	 int n;
	 cin >> n;
	 for (int i = 1; i <= n; i ++ ) {
	 	cin >> a[i];
	 }

	 LL pos = 0, neg = 0;
	 for (int i = n; i > 1; i -- ) {
	 	a[i] -= a[i - 1];
	 }

	 for (int i = 2; i <= n; i ++ ) {
	 	if(a[i] > 0) pos += a[i];
	 	else neg -= a[i];
	 }

	 cout << min(pos, neg) + abs(pos - neg) << endl;
	 cout << abs(pos - neg) + 1 << endl;

}

int main()
{
    IOS;
    int t = 1;
    while(t -- )
        solve();

    return 0;
}
