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
	 string s;
	 cin >> n >> s;

	 int j = 0, cnt = 0, res = 0;
	 for (int i = 0; i <= n; i ++ ) {
	 	if(s[i] != 'x') {
	 		j = i;
	 		if (cnt > 2) res += (cnt - 2);
	 		cnt = 0;
	 	}
	 	else
	 		cnt ++ ;
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
