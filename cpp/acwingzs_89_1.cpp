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
	int n;
	cin >> n;
	int s = 0;
	for(int i = 1; i <= n; i ++ )
	{
		int a;
		cin >> a;
		s += a;
	}
	
	int ans = 0;
	for(int i = 1; i <= 5; i ++ )
		if((s + i) % (n + 1) != 1)
			ans ++ ;
	cout << ans << endl;
	
}

int main()
{
	IOS;
	int t = 1;
	while(t -- )
		solve();
		
	return 0;
}

