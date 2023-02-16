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

	 LL cnt = 1, cot = 0, count = 1;
	 LL res = a[1], ans = 0;
	 LL id = 1;
	 for (LL i = 1; i <= n; i ++ ) {
	 	ans += a[i];
	 	cot ++ ;
	 	if (cnt == cot || i == n) {
	 		cnt *= 2;
	 		cot = 0;
	 		if (ans > res) {
	 			id = count;
	 			res = ans;
	 		}
	 		count ++ ;
	 		ans = 0;
	 	}
	 }

	 cout << id << endl;

}

int main()
{
    IOS;
    int t = 1;
    while(t -- )
        solve();

    return 0;
}
