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

const int N = 1e5 + 10, INF = 1e9;
LL a[N];

void solve()
{
	int n;
	cin >> n;
	a[1] = 1; a[2] = 1;
	for(int i = 3; i <= n; i ++ )
	{
		a[i] = a[i - 1] + a[i - 2];
		if(a[i] > INF)
			a[i] = 1;
	}
	
	for(int i = 1; i <= n; i ++ )
		cout << a[i] << " ";
	
}

int main()
{
	IOS;
	int t = 1;
	while(t -- )
		solve();
		
	return 0;
}

