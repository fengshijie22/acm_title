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

const int N = 1e5 + 10;
int a[N];
int to[N];

void solve()
{
	int n;
	cin >> n;
	int cnto = 0, cntuo = 0; 
	for(int i = 1; i <= n; i ++ )
	{
		cin >> a[i];
		if(a[i] % 2 == 1)
		{
			to[i] = 1;
			cnto ++ ;
		}
		else
		{
			to[i] = 0;
			cntuo ++ ;
		}
	}
	
	if(cnto >= 3)
	{
		cout << "YES" << endl;
		int c = 0;
		for(int i = 1; i <= n; i ++ )
		{
			
			if(to[i] == 1)
				cout << i << " ", c ++ ;
			if(c == 3)
			{
				cout << endl;
				return ;
			}
		}
	}
	
	if(cnto >= 1 && cntuo >= 2)
	{
		cout << "YES" << endl;
		int c1 = 0, c2 = 0;
		for(int i = 1; i <= n; i ++ )
		{
			
			if(to[i] == 1 && c1 < 1)
				cout << i << " ", c1 ++ ;
			if(to[i] == 0 && c2 < 2)
				cout << i << " ", c2 ++ ;
			if(c1 + c2 == 3)
			{
				cout << endl;
				return ;
			}
		}
	}
	
	cout << "NO" << endl;
	
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

