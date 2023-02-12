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

int gcd(int a, int b)
{
	return b ? gcd(b, a % b) : a;
}

void solve()
{
	int a, b;
	cin >> a >> b;
	//int res = gcd(a, b);
	int res = __gcd(a, b);
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

