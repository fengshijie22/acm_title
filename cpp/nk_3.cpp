#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;

typedef long long LL;

void solve()
{
	int n;
	cin >> n;
	
	if(n >= 4)
	{
		if(n % 4 <= 2)
		{
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
				int t = n / 4 - 1;
				for(int i = 1; i <= n; i ++ )
				{
					if(i <= t * 4)
					{
						if(i % 4 == 1 || i % 4 == 2)
							cout << i + 2 << " ";
						else
							cout << i - 2 << " ";						
					}
					else
					{
						if(i % 5 == 1 || i % 5 == 2 || i % 5 == 3)
							cout << i + 2 << " ";
						else
							cout << i - 3 << " ";
					}
				}
			}
			if(n % 4 == 2)
			{
				int t = n / 4 - 1;
				for(int i = 1; i <= n; i ++ )
				{
					if(i <= t * 4)
					{
						if(i % 4 == 1 || i % 4 == 2)
							cout << i + 2 << " ";
						else
							cout << i - 2 << " ";						
					}
					else
					{
						if(i % 6 == 1 || i % 6 == 2 || i % 6 == 3)
							cout << i + 3 << " ";
						else
							cout << i - 3 << " ";
					}
				}
			}
		}
		else if(n % 5 <= 1)
		{
			if(n % 5 == 0)
			{
				for(int i = 1; i <= n; i ++ )
				{
					if(i % 5 == 1 || i % 5 == 2 || i % 5 == 3)
						cout << i + 2 << " ";
					else
						cout << i - 3 << " ";
 				}				
			}
			if(n % 5 == 1)
			{
				int t = n / 5 - 1;
				for(int i = 1; i <= n; i ++ )
				{
					if(i <= 5 * t)
					{
						if(i % 5 == 1 || i % 5 == 2 || i % 5 == 3)
							cout << i + 2 << " ";
						else
							cout << i - 3 << " ";
					}
					else
					{
						if(i % 6 == 1 || i % 6 == 2 || i % 6 == 3)
							cout << i + 3 << " ";
						else
							cout << i - 3 << " ";
					}
				}
			}
		}
		else
			cout << -1 << endl;
	}
	else
		cout << -1 << endl;
	
}

int main()
{
	int t = 1;
	while(t -- )
		solve();
	
	return 0;
}
