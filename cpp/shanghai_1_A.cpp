#include <iostream>
#include <cstring>
#include <algorithm>
#include <set>
#define IOS ios::sync_with_stdio(0); \
			cin.tie(0);              \
			cout.tie(0);
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;
set<string> mp1;
set<string> mp2;

void solve()
{
	int n;
	cin >> n;
	int cnt = 0;
	for(int i = 1; i <= n; i ++ )
	{
		string a, b;
		cin >> a >> b;
		if(b == "No")
		{
			if(!mp2.count(a))
			{
				cnt ++ ;
				mp1.insert(a);
			}
		}
		else
		{
			if(b == "lbromine") continue;
			if(mp1.count(b))
			{
				cnt -- ;
				mp1.erase(mp1.find(b));
			}
			else
			{
				mp2.insert(b);
			}
		}
	}
	cout << cnt << endl;
}

int main()
{
	IOS;
	int t = 1;
	while(t -- )
		solve();
		
	return 0;
}

