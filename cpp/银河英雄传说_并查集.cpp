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
int p[N], dist[N], si[N];

int find(int id) {
	if (p[id] != id) {
		int u = find(p[id]);
		dist[id] += dist[p[id]];
		p[id] = u;
	}
	return p[id];
}

void solve()
{
	 int m;
	 cin >> m;
	 for (int i = 0; i < N; i ++ ) {
	 	p[i] = i;
	 	si[i] = 1;
	 	dist[i] = 0;
	 }

	 while (m -- ) {
	 	string s;
	 	int a, b;
	 	cin >> s >> a >> b;
	 	if (s[0] == 'M') {
	 		int pa = find(a), pb = find(b);
	 		if (pa != pb) {
	 			p[pa] = pb;
	 			dist[pa] = si[pb];
	 			si[pb] += si[pa];
	 		}
	 	}
	 	else if (s[0] == 'C') {
	 		int pa = find(a), pb = find(b);
	 		if (pa != pb) cout << -1 << endl;
	 		else {
	 			cout << max(0, abs(dist[a] - dist[b]) - 1) << endl;
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
