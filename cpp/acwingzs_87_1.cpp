#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

typedef long long LL;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;

int g[10][10];

void solve()
{
	int x, y;
	for(int i = 1; i <= 5; i ++ )
	{
		for(int j = 1; j <= 5; j ++ )
		{
			cin >> g[i][j];
			if(g[i][j] == 1)
				x = i, y = j;
		}
	}
	
	int tx = (3 - x > 0 ? 3 - x : x - 3);
	int ty = (3 - y > 0 ? 3 - y : y - 3);
	cout << tx + ty << endl;
	
}

int main()
{
	int t = 1;
	while(t -- )
		solve();
		
	return 0;
}

