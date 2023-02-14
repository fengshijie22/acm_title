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
int a[N];

void solve()
{
	 int n, k;
	 cin >> n >> k;
	 for (int i = 1; i <= n; i ++ ) {
	 	cin >> a[i];
	 }

	 int cnt = 1, idx = 1, res = a[1];
	 while (1) {
	 	bool pd = false;
	 	int w = (k * cnt + k * (cnt - 1) + 1) * k / 2;
	 	while (res < w) {
	 		if(idx >= n) {
	 			pd = true;
	 			break;
	 		}
	 		res += a[ ++ idx ];
	 	}
	 	if (res >= w) {
	 		cnt ++ ;
	 		res = a[ ++ idx ];
	 	}
	 	if(pd) {
	 		cout << cnt - 1 << endl;
	 		break;
	 	}

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
