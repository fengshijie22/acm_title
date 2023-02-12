#include <iostream>
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

const int INF = 0x3f3f3f3f;
typedef long long LL;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;

void solve()
{
	LL x;
	cin >> x;
	LL l, r;
	cin >> l >> r;
    if(x < l)
    {
        printf("%.10lf\n", 0);
        return ;
    }
    if(x > r)
    {
        cout << "1.0000000000" << endl;
        return ;
    }
	double res = ((x - l) * 1.0) / ((r - l + 1) * 1.0);
	printf("%.10lf\n", res);
}

int main()
{
	IOS;
	int t = 1;
	while(t -- )
		solve();
		
	return 0;
}

