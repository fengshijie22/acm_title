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
#define IOS ios::sync_with_stdio(false); \
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
map<LL, LL> ma;

LL get(LL a, LL b) 
{
	LL res = 1;
	res = res * (a - 1) * a;

	return res;
}

void solve()
{
	LL n;
	cin >> n;
	for (LL i = 1; i <= n; i ++ ) {
		cin >> a[i];
		ma[a[i]] ++ ;
	}

	LL res = n;
	for (auto it : ma) {
		LL x = it.second;
		if (x > 1)
			res += get(x, 2);
	}
	cout << res << endl;

}

int main()
{
    IOS;
    int t = 1;
    while(t -- )
        solve();

    return 0;
}
