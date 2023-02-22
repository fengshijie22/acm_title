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

const int N = 1e5 + 3;
int h[N], e[N], ne[N], idx = 0;

int get_head(int a) {
	return (a % N + N) % N;
}

void add(int a, int b) {
	e[idx] = b, ne[idx] = h[a], h[a] = idx ++ ;
}

bool find(int a, int b) {
	for (int i = h[a]; i != -1; i = ne[i]) {
		if (e[i] == b) {
			return true;
		}
	}
	return false;
}

void solve()
{
	 memset(h, -1, sizeof h);
	 int n;
	 cin >> n;
	 for (int i = 1; i <= n; i ++ ) {
	 	string s;
	 	int a;
	 	cin >> s >> a;
	 	if (s[0] == 'I') {
	 		int k = get_head(a);
	 		add(k, a);
	 	}
	 	else {
	 		int k = get_head(a);
	 		if (find(k, a)) {
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
