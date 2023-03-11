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

const int N = 1010;
int fa[N], son_l[N], son_r[N];

void solve()
{
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i ++ ) {
		int a, b;
		cin >> a >> b;
		if (a != -1) fa[a] = i;
		if (b != -1) fa[b] = i;
	}

	while (m -- ) {
		int idx_l = 0, idx_r = 0;
		int a, b;
		cin >> a >> b;
		for (int i = a; i != 0; i = fa[i]) {
			son_l[idx_l ++ ] = i; 
		}
		for (int i = b; i != 0; i = fa[i]) {
			son_r[idx_r ++ ] = i;
		}

		for (int i = idx_l - 1, j = idx_r - 1; i >= 0 && j >= 0; i -- , j -- ) {
			if (son_l[i] == son_r[j]) {
				idx_l -- ; idx_r -- ;
			}
			else {
				break;
			}
		}

		cout << idx_l + idx_r << endl;

	}

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
