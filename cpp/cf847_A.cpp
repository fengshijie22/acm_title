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
	string end = "314159265358979323846264338327";
	string s;
	cin >> s;
	for(int i = 0; i <= 30; i ++ )
	{
		if(s[i] != end[i])
		{
			cout << i << endl;
			return ;
		}
	}
	cout << 30 << endl;
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

