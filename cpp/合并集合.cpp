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
int p[N];

int find(int id) {
	if (p[id] != id) {
		p[id] = find(p[id]);
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
	 while (m -- ) {
	 	string s;
	 	int a, b;
	 	cin >> s >> a >> b;
	 	if (s[0] == 'M') {
	 		a = find(a), b = find(b);
	 		p[a] = b;
	 	}
	 	else {
	 		a = find(a), b = find(b);
	 		if (a == b) {
	 			cout << "Yes" << endl;
	 		}
	 		else {
	 			cout << "No" << endl;
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
