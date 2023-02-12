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

bool is_prime(int x)
{
	if(x < 2) return false;
	for(int i = 2; i <= x / i; i ++ )
		if(x % i == 0)
			return false;
	return true;
}

void solve()
{
	int n;
	cin >> n;
	while(n -- )
	{
		int a;
		cin >> a;
		if(is_prime(a))
			cout << "Yes" << endl;
		else
			cout << "No" << endl;
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

