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

const int N = 1e5 + 10;
int p[N], co[N];

int find(int id) {
	if (p[id] != id) p[id] = find(p[id]);
	return p[id];
}

void solve()
{
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i ++ ) {
		p[i] = i;
		co[i] = 1;
	}
	while (m -- ) {
		string s;
		cin >> s;
		if (s[0] == 'C') {
			int a, b;
			cin >> a >> b;
			int pa = find(a), pb = find(b);
			if (pa != pb) {
				co[pb] += co[pa];
				p[pa] = pb;
			}
		}
		if (s[0] == 'Q') {
			if (s[1] == '1') {
				int a, b;
				cin >> a >> b;
				if (find(a) == find(b)) {
					cout << "Yes" << endl;
				}
				else {
					cout << "No" << endl;
				}
			}
			else {
				int a;
				cin >> a;
				cout << co[find(a)] << endl;;
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
