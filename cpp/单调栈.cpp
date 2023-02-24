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
int a[N], q[N], head = 1, tail = 0, idx = 2;

void solve()
{
	 int n;
	 cin >> n;
	 for (int i = 1; i <= n; i ++ ) {
	 	cin >> a[i];
	 }

	 cout << "-1" << " ";
	 q[++ tail ] = a[1];

	 while (head <= tail && idx <= n) {
	 	while (a[idx] <= q[tail] && head <= tail) {
	 		tail -- ;
	 	}
	 	if (head > tail) {
	 		cout << "-1" << " ";
	 	}
	 	else {
	 		cout << q[tail] << " ";
	 	}
	 	q[++ tail ] = a[idx ++ ];

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
