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

const int N = 210;
int a[N], b[N], idx1, idx2;

void solve()
{
	memset(a, 0, sizeof a);
	memset(b, 0, sizeof b);
	idx1 = 0, idx2 = 0;
	string s, m;
	int n;
	cin >> n >> s;
	m = s;
	for (int i = 0; i < n - 1; i ++ ) {
		if (s[i] != 'W') {
	 		a[++ idx1 ] = i + 1;
	 		s[i] = 'W';
	 		if (s[i + 1] == 'W') s[i + 1] = 'B';
	 		else s[i + 1] = 'W';
	 	}
	 }

	for (int i = 0; i < n - 1; i ++ ) {
	 	if (m[i] != 'B') {
	 		b[++ idx2 ] = i + 1;
	 		m[i] = 'B';
	 		if (m[i + 1] == 'W') m[i + 1] = 'B';
	 		else m[i + 1] = 'W';
	 	}
	 }

	 bool pd1 = true, pd2 = true;
	 for (int i = 0; i < n; i ++ ) {
	 	if (s[i] != 'W') {
	 		pd1 = false;
	 	}

	 	if (m[i] != 'B') {
	 		pd2 = false;
	 	}
	 }

	 if (pd1 || pd2) {
	 	if (pd1) {
	 		cout << idx1 << endl;
	 		for (int i = 1; i <= idx1; i ++ ) {
	 			cout << a[i] << " ";
	 		}
	 		if (idx1 != 0) {
	 			cout << endl;
	 		}
	 	}
	 	else if (pd2) {
	 		cout << idx2 << endl;
	 		for (int i = 1; i <= idx2; i ++ ) {
	 			cout << b[i] << " ";
	 		}
	 		if (idx2 != 0) {
	 			cout << endl;
	 		}
	 	}
	 }

	 else {
	 	cout << -1 << endl;
	 }


}

int main()
{
    IOS;
    int t = 1;
    cin >> t;
    while(t -- )
        solve();

    return 0;
}
