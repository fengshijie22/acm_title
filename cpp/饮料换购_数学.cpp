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

void solve()
{
	 int n;
	 cin >> n;
	 int res = n;
	 while (n >= 3) {
	 	res += (n / 3);
	 	n = (n / 3) + (n % 3);
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
