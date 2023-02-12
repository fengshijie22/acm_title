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
set<string> mp;
string str[1010];

void solve()
{
	int n, m;
	cin >> n >> m;
	for(int i = 1; i <= n; i ++ )
	{
		string s;
		cin >> s;
		for(int j = 3; j < 6; j ++ )
			str[i] += s[j];
	}
	int cnt = 0;
	for(int i = 1; i <= m; i ++ )
	{
		string s;
		cin >> s;
		mp.insert(s);
	}
	for(int i = 1; i <= n; i ++ )
	{
		if(mp.count(str[i]))
			cnt ++ ;
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

