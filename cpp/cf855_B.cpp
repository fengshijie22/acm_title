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

int a[26][2];

void solve()
{
	memset(a, 0, sizeof a);
	int n, k;
	cin >> n >> k;
	string s;
	cin >> s;
	for (int i = 0; i < s.size(); i ++ ) {
		if (s[i] >= 'A' && s[i] <= 'Z') {
			a[s[i] - 'A'][1] ++ ;
		}
		if (s[i] >= 'a' && s[i] <= 'z') {
			a[s[i] - 'a'][0] ++ ;
		}
	}

	int res = 0;
	for (int i = 0; i < 26; i ++ ) {
		res += min(a[i][0], a[i][1]);
		int t = abs(a[i][0] - a[i][1]) / 2;
		if (t <= k) {
			res += t;
			k -= t;
		}
		else {
			res += k;
			k = 0;
		}
	}
	cout << res << endl;

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
