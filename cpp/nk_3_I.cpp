#include <iostream>
#include <cstring>
#include <algorithm>
#define IOS ios::sync_with_stdio(0); \
			cin.tie(0);              \
			cout.tie(0);
using namespace std;

typedef long long LL;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;

bool is_primes(LL n)
{
	if(n == 1) return false;
	for(LL i = 2; i <= n / i; i ++ )
		if(n % i == 0) return false;
	return true;
}

void solve()
{
	LL n;
	cin >> n;
	if(n % 2 == 1)
	{
		if(n == 1) cout << 3 << endl;
		else if(n == 3) cout << 4 << endl;
		else if(n == 5) cout << -1 << endl;
		else if(n == 7) cout << 8 << endl;
		else
		{
			LL i;
			for(i = 3; i < (n - 1) / 2; i ++ )
			{
				if(is_primes(i) && is_primes(n - i - 1)) break;
			}
			cout << i * (n - i - 1) << endl;
		}
	}
	else
	{
		if(is_primes(n - 1)) cout << (n - 1) * (n - 1) << endl;
		else if(is_primes(n - 3)) cout << 2 * (n - 3) << endl;
	}
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

