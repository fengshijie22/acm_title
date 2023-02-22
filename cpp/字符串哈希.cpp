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

typedef unsigned long long ULL;
const int N = 1e5 + 10, P = 133;
ULL p[N], ha[N];
char str[N];

ULL get(int l, int r) {
	return ha[r] - ha[l - 1] * p[r - l + 1]; 
}

void solve()
{
	 int n, m;
	 cin >> n >> m >> str + 1;

	 p[0] = 1;
	 for (int i = 1; i <= n; i ++ ) {
	 	p[i] = p[i - 1] * P;
	 	ha[i] = ha[i - 1] * P + str[i];
	 }

	 while (m -- ) {
	 	int al, ar, bl, br;
	 	cin >> al >> ar >> bl >> br;
	 	if (get(al, ar) == get(bl, br)) {
	 		cout << "Yes" << endl;
	 	}
	 	else {
	 		cout << "No" << endl;
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
