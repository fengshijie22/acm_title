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

const int N = 10;
int con[N], n;
bool st[N];

void dfs(int u) {
	if (u >= n) {
		for (int i = 0; i < n; i ++ ) {
			cout << con[i] << " ";
		}
		cout << endl;
		return ;
	}

	for (int i = 1; i <= n; i ++ ) {
		if (!st[i]) {
			st[i] = true;
			con[u] = i;
			dfs(u + 1);
			st[i] = false;
			con[u] = 0;
		}
	}

}

void solve()
{
	cin >> n;

	dfs(0);
}

int main()
{
    IOS;
    int t = 1;
    while(t -- )
        solve();

    return 0;
}
