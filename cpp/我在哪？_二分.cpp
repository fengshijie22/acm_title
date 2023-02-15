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

const int N = 110, P = 131;
typedef unsigned long long ULL;
ULL ha[N], p[N];
int n;
char s[N];

ULL get(int l, int r) {
	return ha[r] - ha[l - 1] * p[r - l + 1];
}

bool check(int k) {
	unordered_set<ULL> t;
	for (int i = 1; i + k - 1 <= n; i ++ ) {
		if(t.count(get(i, i + k - 1))) return false;
		else t.insert(get(i, i + k - 1));
	}
	return true;
}

void solve()
{
	cin >> n >> s + 1;
	p[0] = 1;
	for (int i = 1; i <= n; i ++ ) {
		ha[i] = ha[i - 1] * P + s[i];
		p[i] = p[i - 1] * P;
	}

	int l = 1, r = n;
	while (l < r) {
		int mid = (l + r) >> 1;
		if(check(mid)) r = mid;
		else l = mid + 1;
	}

	cout << l << endl;

}

int main()
{
    IOS;
    int t = 1;
    while(t -- )
        solve();

    return 0;
}
