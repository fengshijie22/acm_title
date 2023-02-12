#include <iostream>
#include <cstring>
#include <algorithm>
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

// N的欧拉函数 = N(1 - 1 / p1)(1 - 1 / p2) ··· (1 - 1 / pk);
// p1, p2, p3, ··· , pk 为N的质因数

void solve()
{
	int n;
	cin >> n;
	int res = n;
	for(int i = 2; i <= n / i; i ++ )
	{
		if(n % i == 0)
		{
			res = res / i * (i - 1);
			while(n % i == 0) n /= i;
		}
	}
	if(n > 1) res = res / n * (n - 1);
	cout << res << endl;
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

