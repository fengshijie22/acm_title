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
	while(n -- )
	{
		int x;
		cin >> x;
		for(int i = 2; i <= x / i; i ++ )
		{
			while(x % i == 0)
			{
				x /= i;
				primes[i] ++ ;
			}
		}
		if(x > 1) primes[x] ++ ;
	}
	
	LL res = 1;
	for(auto prime : primes)
	{
		int p = prime.first, a = prime.second;
		LL t = 1;
		while(a -- ) t = (t * p + 1) % mod;
		res = res * t % mod;
	}
	
	cout << res << endl;
	
}

int main()
{
	IOS;
	int t = 1;
	while(t -- )
		solve();
		
	return 0;
}

