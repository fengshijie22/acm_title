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

const int N = 3e6 + 10;
int tire[N][2], idx;
int n;

void insert(int x) {
    int p = 0;
    for (int i = 29; i >= 0; i -- ) {
        int u = x >> i & 1;
        if (tire[p][u] == false) tire[p][u] = ++ idx;
        p = tire[p][u]; 
    }
}

int dfs(int u, int d) {
    if (d == -1) return 0;
    int f[2];
    for (int i = 0; i < 2; i ++ ) {
        int p = tire[u][i];
        if (p) {
            f[i] = dfs(p, d - 1);
        }
        else {
            f[i] = -1;
        }
    }

    LL res = INFL;
    for (int i = 0; i < 2; i ++ ) {
        int t = 0;
        for (int j = 0; j < 2; j ++ ) {
            if (f[j] != -1) {
                t = max(t, f[j] + ((i ^ j) << d));
            }
        }
        res = min(res, (LL)t);
    }

    return res;

}

void solve()
{
	cin >> n;
    for (int i = 1; i <= n; i ++ ) {
        int x;
        cin >> x;
        insert(x);
    }

    cout << dfs(0, 29) << endl;

}

int main()
{
    IOS;
    int t = 1;
    while(t -- )
        solve();

    return 0;
}
