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

const int INF = 0x3f3f3f3f, mod = 1e9 + 7;
typedef long long LL;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;

void solve()
{
	int n;
	cin >> n;
	unordered_map<int, int> primes;
	for(int i = 1; i <= n; i ++ )
	{
		int x;
		cin >> x;
		for(int j = 2; j <= x; j ++ )
		{
			while(x % j == 0)
			{
				x /= j;
				primes[j] ++ ;
			}
		}
		if(x > 1) primes[x] ++ ;
	}
	
	LL res = 1;
	for(auto prime : primes)
		 res *= (prime.second + 1) % mod;
		 
	cout << res % mod << endl;
	
}

int main()
{
	IOS;
	int t = 1;
	while(t -- )
		solve();
		
	return 0;
}

