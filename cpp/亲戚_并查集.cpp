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

const int N = 2e4 + 10;
int p[N];

int find(int id) {
	if (p[id] != id) p[id] = find(p[id]);
	return p[id];
}

void solve()
{
	 int n, m;
	 //cin >> n >> m; // TLE
	 scanf("%d%d", &n, &m);
	 for (int i = 1; i <= n; i ++ ) {
	 	p[i] = i;
	 }
	 while (m -- ) {
	 	int a, b;
		//cin >> a >> b;
		scanf("%d%d", &a, &b);	 	
	 	a = find(a), b = find(b);
	 	if (a != b) {
	 		p[a] = b;
	 	}
	 }

	 //cin >> m;
	 scanf("%d", &m);
	 while (m -- ) {
	 	int a, b;
	 	//cin >> a >> b;
	 	scanf("%d%d", &a, &b);
	 	a = find(a), b = find(b);
	 	if (a == b) {
	 		//cout << "Yes" << endl;
	 		printf("Yes\n");
	 	}
	 	else {
	 		//cout << "No" << endl;
	 		printf("No\n");
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
