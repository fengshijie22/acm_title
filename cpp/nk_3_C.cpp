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

void solve()
{
	int n;
	cin >> n;
	if(n < 4 || n == 7)
	{
		cout << -1 << endl;
		return ;
	}
	int k = n / 4;
	if(n % 4 == 0)
	{
		for(int i = 1; i <= n; i ++ )
		{
			if(i % 4 == 1 || i % 4 == 2)
				cout << i + 2 << " ";
			else
				cout << i - 2 << " ";
		}
	}
	if(n % 4 == 1)
	{
		for(int i = 1; i <= n; i ++ )
		{
			if(i <= 4 * (k - 1))
			{
				if(i % 4 == 1 || i % 4 == 2)
					cout << i + 2 << " ";
				else
					cout << i - 2 << " ";
			}
			else
			{
				int t = i - 4 * (k - 1);
				if(t % 5 == 1 || t % 5 == 2 || t % 5 == 3)
					cout << i + 2 << " ";
				else
					cout << i - 3 << " ";
			}
		}
	}
	if(n % 4 == 2)
	{
		for(int i = 1; i <= n; i ++ )
		{
			if(i <= 4 * (k - 1))
			{
				if(i % 4 == 1 || i % 4 == 2)
					cout << i + 2 << " ";
				else
					cout << i - 2 << " ";
			}
			else
			{
				int t = i - 4 * (k - 1);
				if(t % 6 == 1 || t % 6 == 2 || t % 6 == 3)
					cout << i + 3 << " ";
				else
					cout << i - 3 << " ";
			}
		} 
	}
	if(n % 4 == 3)
	{
		for(int i = 1; i <= n; i ++ )
		{
			if(i <= 4 * (k - 2))
			{
				if(i % 4 == 1 || i % 4 == 2)
					cout << i + 2 << " ";
				else
					cout << i - 2 << " ";
			}
			else if(i > 4 * (k - 2) && i <= 4 * (k - 2) + 5)
			{
				int t = i - 4 * (k - 2);
				if(t % 5 == 1 || t % 5 == 2 || t % 5 == 3)
					cout << i + 2 << " ";
				else
					cout << i - 3 << " ";
			}
			else
			{
				int t = i - (4 * (k - 2) + 5);
				if(t % 6 == 1 || t % 6 == 2 || t % 6 == 3)
					cout << i + 3 << " ";
				else
					cout << i - 3 << " ";
			}
		}
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

