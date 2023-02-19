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

const int mod = 9901;

LL ksm(LL a, LL b) {
	LL res = 1;
	while (b) {
		if (b % 2 == 1) {
			res = res * a % mod;
		}
		b >>= 1;
		a = a * a % mod;
	}

	return res;
}

LL sum(LL p, LL k) {
	if (k == 0) {
		return 1;
	}

	if (k % 2 == 0) {
		return ((ksm(p, k / 2) + 1) * sum(p, k / 2 - 1) + ksm(p, k)) % mod;
	}
	else {
		return ((ksm(p, (k + 1) / 2) + 1) * sum(p, (k - 1) / 2)) % mod;
	}

}

void solve()
{
	LL a, b;
	cin >> a >> b;
	LL ans = 1;
	for (LL i = 2; i <= a; i ++ ) {
		int s = 0;
		while (a % i == 0) {
			s ++ ;
			a /= i;
		}
		if (s) {
			ans = ans * sum(i, s * b);
		}
	} 

	if (a == 0) {
		cout << 0 << endl;
	}
	else {
		cout << ans << endl;
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
