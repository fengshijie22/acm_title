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

const int N = 1e5 + 10, M = 1e6 + 10;
char s[M], p[N];
int ne[N];

void solve()
{
	 int n, m;
	 cin >> n >> p + 1 >> m >> s + 1;
	 for (int i = 2, j = 0; i <= n; i ++ ) {
	 	while (j && p[i] != p[j + 1]) {
	 		j = ne[j];
	 	}
	 	if (p[i] == p[j + 1]) {
	 		j ++ ;
	 	}
	 	ne[i] = j;
	 }

	 for (int i = 1, j = 0; i <= m; i ++ ) {
	 	while (j && s[i] != p[j + 1]) {
	 		j = ne[j];
	 	}
	 	if (s[i] == p[j + 1]) {
	 		j ++ ;
	 	}
	 	if (j == n) {
	 		cout << i - n << " ";
	 		j = ne[j];
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
