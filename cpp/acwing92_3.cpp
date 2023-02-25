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

const int N = 1010;
int p[N], bi[N];
vector<int> v;

int find(int id) {
	if (p[id] != id) {
		p[id] = find(p[id]);
	}

	return p[id];
}

bool cmp(int a, int b) {
	return a > b;
}

void solve()
{
	 int n, m;
	 cin >> n >> m;
	 for (int i = 1; i <= n; i ++ ) {
	 	p[i] = i;
	 	bi[i] = 1;
	 }

	 int res = 0, ans = 0;

	 while (m -- ) {
	 	v.clear();
	 	ans = 0;
	 	int a, b;
	 	cin >> a >> b;
	 	int pa = find(a), pb = find(b);
	 	if (pa != pb) {
	 		bi[pb] += bi[pa];
	 		p[pa] = pb;
	 	}
	 	else {
	 		res ++ ;
	 	}
	 	for (int i = 1; i <= n; i ++ ) {
	 		if (find(i) == i) {
	 			v.push_back(bi[i]);
	 		}
	 	}

	 	sort(v.begin(), v.end(), cmp);

	 	for (int i = 0; i <= res && i < v.size(); i ++ ) {
	 		ans += v[i];
	 	}

	 	cout << ans - 1 << endl;

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
