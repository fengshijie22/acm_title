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

const int N = 2e5 + 10;
int v[N], a[N], idx = 0;

void solve()
{
	 memset(v, 0, sizeof v);
	 int n;
	 cin >> n;
	 idx = 0;
	 for (int i = 1; i <= n; i ++ ) {
	 	cin >> a[i];
	 	++ idx;
	 	if(a[i] != 0) {
	 		int c = min(a[i], idx);
	 		v[idx - c + 1] += 1, v[idx + 1] -= 1;
	 	}
	 }

	 for (int i = 1; i <= idx; i ++ ) {
	 	v[i] += v[i - 1];
	 }

	 for (int i = 1; i <= idx; i ++ ) {
	 	if(v[i] > 0) cout << 1 << " ";
	 	else cout << 0 << " ";
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
