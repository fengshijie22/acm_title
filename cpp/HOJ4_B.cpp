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


void solve()
{
	 LL a, b;
	 cin >> a;
	 b = a;
	 LL res = 0;
	 while(b) {
	 	res += (b % 10);
	 	b /= 10;
	 }
	 LL cot = 0;
	 cot = 7 * a + 21 * res;
	 cout << cot << endl;


}

int main()
{
    IOS;
    int t = 1;
    while(t -- )
        solve();

    return 0;
}
