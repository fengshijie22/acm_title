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

const int N = 1e6 + 10;
int a[N], q[N], head = 1, tail = 0;

void solve()
{
	 int n, k;
	 cin >> n >> k;
	 for (int i = 1; i <= n; i ++ ) {
	 	cin >> a[i];
	 }

	 for (int i = 1; i <= n; i ++ ) {
	 	while (head <= tail && a[q[tail]] >= a[i]) {
	 		tail -- ;
	 	}
	 	q[++ tail] = i;
	 	if (i >= k) {
	 		while (head <= tail && q[head] <= i - k) {
	 			head ++ ;
	 		}
	 		cout << a[q[head]] << " ";
	 	}
	 }
	 cout << endl;

	 head = 1, tail = 0;
	 for (int i = 1; i <= n; i ++ ) {
	 	while (head <= tail && a[q[tail]] <= a[i]) {
	 		tail -- ;
	 	}
	 	q[++ tail ] = i;
	 	if (i >= k) {
	 		while (head <= tail && q[head] <= i - k) {
	 			head ++ ;
	 		}
	 		cout << a[q[head]] << " ";
	 	}
	 }
	 cout << endl;

}

int main()
{
    IOS;
    int t = 1;
    while(t -- )
        solve();

    return 0;
}
