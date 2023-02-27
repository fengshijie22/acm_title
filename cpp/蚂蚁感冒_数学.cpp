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
int x[N];

void solve()
{
	 int n;
	 cin >> n;
	 int l_r = 0, l_l = 0, r_l = 0, r_r = 0;
	 int m = 0;
	 for (int i = 1; i <= n; i ++ ) {
	 	cin >> x[i];
	 }

	 m = abs(x[1]);

	 for (int i = 2; i <= n; i ++ ) {
	 	if (x[i] > 0 && abs(x[i]) > m) {
	 		r_r ++ ;
	 	}
	 	if (x[i] < 0 && abs(x[i]) > m) {
	 		r_l ++ ;
	 	}
	 	if (x[i] > 0 && abs(x[i]) < m) {
	 		l_r ++ ;
	 	}
	 	if (x[i] > 0 && abs(x[i]) < m) {
	 		l_l ++ ;
	 	}
	 }

	 if (x[1] < 0) {
	 	if (l_r == 0) {
	 		cout << 1 << endl;
	 	}
	 	else {
	 		cout << l_r + r_l + 1 << endl;
	 	}
	 }
	 else {
	 	if (r_l == 0) {
	 		cout << 1 << endl;
	 	}
	 	else {
	 		cout << r_l + l_r + 1 << endl;
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
