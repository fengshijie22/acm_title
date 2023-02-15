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

const int N = 5e6 + 10;
int co[N], n;
bool st[N];

void solve()
{
	cin >> n;
	for (int i = 0; i * i * 2 <= n; i ++ ) {
		for (int j = i; j * j + i * i <= n; j ++) {
			if (!st[i * i + j * j]) {
				co[i * i + j * j] = i + 1;
				st[i * i + j * j] = true;
			}
		}
	}

	for (int a = 0; a * a * 4 <= n; a ++ ) {
		for (int b = a; (b * b + a * a) * 2 <= n; b ++ ) {
			int t = n - a * a - b * b;
			if (st[t]) {
				int c = co[t] - 1;
				int d = sqrt(t - c * c);
				cout << a << " " << b << " " << c << " " << d << endl;
				return ;
			}
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
