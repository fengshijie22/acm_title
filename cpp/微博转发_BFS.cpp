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

const int N = 1e5 + 10, M = 2e5 + 10;
int h[M], e[M], ne[M], idx;
int n, m;
bool st[M];
 
void add(int a, int b) {
	e[idx] = b, ne[idx] = h[a], h[a] = idx ++ ;
}

int bfs(int id) {
	memset(st, false, sizeof st);
	queue<int> q;
	q.push(id);
	st[id] = true;
	int res = 0;
	for (int j = 1; j <= m; j ++ ) {
		int c = q.size();
		for (int k = 1; k <= c; k ++ ) {
			int x = q.front();
			q.pop();
			for (int i = h[x]; i != -1; i = ne[i]) {
				int t = e[i];
				if (st[t]) {
					continue;
				}
				res ++ ;
				st[t] = true;
				q.push(t);
			}
		}
	}
	return res;
}

void solve()
{
	memset(h, -1, sizeof h);
	cin >> n >> m; 
	for (int i = 1; i <= n; i ++ ) {
	 	int x;
	 	cin >> x;
	 	while (x -- ) {
	 		int id;
	 		cin >> id;
	 		add(id, i);
	 	}
	 }

	 int k;
	 cin >> k;
	 while (k -- ) {
	 	int id;
	 	cin >> id;
	 	cout << bfs(id) << endl;
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
