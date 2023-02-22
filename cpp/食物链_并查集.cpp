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

const int N = 5e4 + 10;
int p[N], d[N];

int find(int id) {
	if (p[id] != id) {
		int u = find(p[id]);
		d[id] += d[p[id]];
		p[id] = u;
	}
	return p[id];
}

void solve()
{
	 int n, m;
	 cin >> n >> m;
	 for (int i = 1; i <= n; i ++ ) {
	 	p[i] = i;
	 }
	 int res = 0;
	 for (int i = 1; i <= m; i ++ ) {
	 	int t, a, b;
	 	cin >> t >> a >> b;
	 	if (a > n || b > n) {
	 		res ++ ;
	 		continue;
	 	}
	 	else if (t == 2 && a == b) {
	 		res ++ ;
	 		continue;
	 	}
	 	else {
	 		int pa = find(a), pb = find(b);
	 		if (t == 1) {
		 		if (pa == pb && (d[a] - d[b]) % 3) {
		 			res ++ ;
		 			continue;
		 		}
		 		else if (pa != pb) {
		 			p[pa] = pb;
		 			d[pa] = d[b] - d[a];
		 		}
		 	}
		 	if (t == 2) {
		 		if (pa == pb && (d[a] - d[b] - 1) % 3) {
		 			res ++ ;
		 			continue;
		 		}
		 		else if (pa != pb){
		 			p[pa] = pb;
		 			d[pa] = d[b] - d[a] + 1;
		 		}
		 	}
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
