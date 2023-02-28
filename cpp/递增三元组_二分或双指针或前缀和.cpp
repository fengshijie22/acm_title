//二分
/*
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
LL a[N], b[N], c[N];

bool cmp(int a, int b) {
    return a > b;
}

void solve()
{
	LL n;
	cin >> n;
	for (int i = 1; i <= n; i ++ ) {
		cin >> a[i];
	}
	for (int i = 1; i <= n; i ++ ) {
		cin >> b[i];
	}
	for (int i = 1; i <= n; i ++ ) {
		cin >> c[i];
	}

	sort(a + 1, a + n + 1);
	sort(b + 1, b + n + 1);
	sort(c + 1, c + n + 1, cmp);

	LL ans = 0, al, cl;
	for (int i = 1; i <= n; i ++ ) {
		int x = b[i];
		int l = 0, r = n;
		while (l < r) {
			int mid = (l + r + 1) >> 1;
			if (a[mid] < x) {
				l = mid;
			}
			else {
				r = mid - 1;
			}
		}
		al = l;
		l = 0, r = n;
		while (l < r) {
			int mid = (l + r + 1) >> 1;
			if (c[mid] > x) {
				l = mid;
			}
			else {
				r = mid - 1;
			}
		}
		cl = l;
		ans += (al * cl);
	}

	cout << ans << endl;

}

int main()
{
    IOS;
    int t = 1;
    while(t -- )
        solve();

    return 0;
}
*/

//双指针
/*
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
LL a[N], b[N], c[N];

void solve()
{
	LL n;
	cin >> n;
	for (int i = 1; i <= n; i ++ ) {
		cin >> a[i];
	}
	for (int i = 1; i <= n; i ++ ) {
		cin >> b[i];
	}
	for (int i = 1; i <= n; i ++ ) {
		cin >> c[i];
	}

	sort(a + 1, a + n + 1);
	sort(b + 1, b + n + 1);
	sort(c + 1, c + n + 1);

	LL al = 1, cl = 1, ans = 0;
	for (LL i = 1; i <= n; i ++ ) {
		LL x = b[i];
		while (al <= n && a[al] < x) al ++ ;
		while (cl <= n && c[cl] <= x) cl ++ ;
		ans += ((al - 1) * (n - cl + 1));
	}

	cout << ans << endl;

}

int main()
{
    IOS;
    int t = 1;
    while(t -- )
        solve();

    return 0;
}
*/

//前缀和
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
LL a[N], b[N], c[N];
LL cnt_a[N], cnt_c[N], sum_a[N], sum_c[N];

void solve()
{
	 LL n;
	 cin >> n;
	 for (LL i = 1; i <= n; i ++ ) {
	 	cin >> a[i];
	 	a[i] ++ ;
	 	cnt_a[a[i]] ++ ;
	 }

	 for (LL i = 1; i <= n; i ++ ) {
	 	cin >> b[i];
	 	b[i] ++ ;
	 }

	 for (LL i = 1; i <= n; i ++ ) {
	 	cin >> c[i];
	 	c[i] ++ ;
	 	cnt_c[c[i]] ++ ;
	 }

	 for (LL i = 1; i < N; i ++ ) {
	 	sum_a[i] = sum_a[i - 1] + cnt_a[i];
	 	sum_c[i] = sum_c[i - 1] + cnt_c[i];
	 }

	 LL ans = 0;
	 for (LL i = 1; i <= n; i ++ ) {
	 	LL x = b[i];
	 	ans += (sum_a[x - 1] * (sum_c[N - 1] - sum_c[x]));
	 }

	 cout << ans << endl;

}

int main()
{
    IOS;
    int t = 1;
    while(t -- )
        solve();

    return 0;
}
