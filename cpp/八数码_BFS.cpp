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

int bfs(string s) {
	string e = "12345678x";
	queue<string> q;
	unordered_map<string, int> m;

	q.push(s);
	int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};
	while (q.size()) {
		string c = q.front();
		int dis = m[c];
		q.pop();
		if (c == e) {
			return m[c];
		}
		int k = c.find('x');
		int x = k / 3, y = k % 3;
		for (int i = 0; i < 4; i ++ ) {
			int x_d = x + dx[i], y_d = y + dy[i];
			if (x_d >= 0 && x_d < 3 && y_d >= 0 && y_d < 3) {
				swap(c[3 * x_d + y_d], c[k]);
				if (!m.count(c)) {
					m[c] = dis + 1;
					q.push(c);
				}
				swap(c[x_d * 3 + y_d], c[k]);
			}
		}
	}

	return -1;

}

void solve()
{
	string s, c;
	for (int i = 1; i <= 9; i ++ ) {
		cin >> c;
		s += c;
	}
	cout << bfs(s) << endl;;

}

int main()
{
    IOS;
    int t = 1;
    while(t -- )
        solve();

    return 0;
}
