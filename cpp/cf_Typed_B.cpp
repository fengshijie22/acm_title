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
LL cnt;

void divide(int x)
{
	// 短除法
	 
	for(int i = 2; i <= x / i; i ++ )
	{
		if(x % i == 0) // i 是x的质因数 
		{
			int s = 0;
			while(x % i == 0) // x 能被多少个i整除 
			{
				x /= i;
				s ++ ;
			}
			cnt += (i * s);
		}
	}
	
	if(x > 1) cnt += x;
	cout << cnt << endl;
	
}

void solve()
{	
	int n;
	cin >> n;
	divide(n);
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

