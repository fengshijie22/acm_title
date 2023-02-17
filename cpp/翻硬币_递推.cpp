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

string s, m;

void turn(int id) {
	if (s[id] == 'o') s[id] = '*';
	else s[id] = 'o';
}

void solve()
{
	 cin >> s >> m;
	 int n = s.size(), res = 0;
	 for (int i = 0; i < n - 1; i ++ ) {
	 	if (s[i] != m[i]) {
	 		turn(i);
	 		turn(i + 1);
	 		res ++ ;
	 	}
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
