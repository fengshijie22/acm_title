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

// 求a ^ k % p; 
LL q_mi(LL a, LL k, LL p)
{
	LL res = 1;
	while(k)
	{
		if(k & 1) // 如果当前k的二进制第一位为1 
			res = res * a % p; // 更新res
		a = a * a % p; // a^2^b变成a^2^(b+1)
		k >>= 1; // k删去第一位 
	}
	return res;
}

void solve()
{
	LL a, k, p;
	cin >> a >> k >> p;
	LL res = q_mi(a, k, p);
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

