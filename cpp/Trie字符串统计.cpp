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
string str;
int ma[N][26], cnt[N], idx;

void add_s() {
	int p = 0;
	for (int i = 0; i < str.size(); i ++ ) {
		int u = str[i] - 'a';
		if (!ma[p][u]) {
			ma[p][u] = ++ idx;
		} 
		p = ma[p][u];
	}

	cnt[p] ++ ;
}

int find_s() {
	int p = 0;
	for (int i = 0; i < str.size(); i ++ ) {
		int u = str[i] - 'a';
		if (!ma[p][u]) {
			return 0;
		}
		p = ma[p][u];
	}

	return cnt[p];
}

void solve()
{
	 int n;
	 cin >> n;
	 while (n -- ) {
	 	string op;
	 	cin >> op >> str;
	 	if (op[0] == 'I') {
	 		add_s();
	 	}
	 	else {
	 		cout << find_s() << endl;
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
