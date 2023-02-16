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
PII ct[N];
bool st[N];
int cnt[N], pr[N], idx = 0;

void solve()
{
	 int n, m, k;
	 cin >> n >> m >> k;
	 for (int i = 1; i <= n; i ++ ) {
	 	int a, b;
	 	cin >> a >> b;
	 	ct[i] = {a, b};
	 }

	 sort(ct + 1, ct + n + 1);

	 for (int i = 1, j = 1; i <= n; i ++ ) {
	 	int ts = ct[i].first, id = ct[i].second;
	 	cnt[id] ++ ;
	 	int ts1 = ct[j].first, id1 = ct[j].second;
	 	while (ts - ts1 >= m) {
	 		j ++ ;
	 		cnt[id1] -- ;
	 		ts1 = ct[j].first, id1 = ct[j].second;
	 	}
	 	if (cnt[id] >= k && st[id] != true) {
	 		pr[++ idx ] = id;
	 		st[id] = true;
	 	}
	 }

	 sort(pr + 1, pr + idx + 1);

	 for (int i = 1; i <= idx; i ++ ) {
	 	cout << pr[i] << endl;
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
