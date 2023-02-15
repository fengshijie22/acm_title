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
	 int n, q;
	 cin >> n >> q;
	 for (int i = 1; i <= n; i ++ ) {
	 	cin >> a[i];
	 }

	 while(q -- ) {
	 	int k;
	 	cin >> k;
	 	int l = 1, r = n;
	 	while (l < r) {
	 		int mid = (l + r) >> 1;
	 		if (a[mid] >= k) r = mid;
	 		else l = mid + 1;
	 	}

	 	if (a[l] != k) {
	 		cout << -1 << " " << -1 << endl;
	 		continue;
	 	}

	 	cout << l - 1 << " ";
	 	l = 1, r = n;
	 	while (l < r) {
	 		int mid = (l + r + 1) >> 1;
	 		if(a[mid] <= k) l = mid;
	 		else r = mid - 1;
	 	}

	 	cout << l - 1 << endl;

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
