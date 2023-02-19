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

const int N = 35;
int po[N], il[N];
unordered_map<int, int> p, l, r;

int tree(int al, int ar, int bl, int br) {
	int root = po[br];
	int x = p[root];
	if (al < x) l[root] = tree(al, x - 1, bl, bl + x - 1 - al);
	if (ar > x) r[root] = tree(x + 1, ar, bl + x - al, br - 1);
	return root;
}

void bfs(int id) {
	queue<int> q;
	q.push(id);

	while (q.size()) {
		int t = q.front();
		q.pop();
		cout << t << " ";
		if (l.count(t)) q.push(l[t]);
		if (r.count(t)) q.push(r[t]);
	}
}

void solve()
{
	 int n;
	 cin >> n;
	 for (int i = 1; i <= n; i ++ ) {
	 	cin >> po[i];
	 }

	 for (int i = 1; i <= n; i ++ ) {
	 	cin >> il[i];
	 	p[il[i]] = i;
	 }

	 int root = tree(1, n, 1, n);
	 bfs(root);

}

int main()
{
    IOS;
    int t = 1;
    while(t -- )
        solve();

    return 0;
}
