#include <iostream>
#include <cstring>
#include <algorithm>
#include <map>
#include <vector> 
#define IOS ios::sync_with_stdio(0); \
			cin.tie(0);              \
			cout.tie(0);
using namespace std;

typedef long long LL;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;

const int N = 2e5 + 10;
int a[N], b[N];
bool st[N];

void solve()
{
	memset(b, 0, sizeof b);
	memset(st, false, sizeof st);
	int n;
	cin >> n;
	for(int i = 1; i <= n; i ++ )
	{
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	vector<PII> p;
	int e = a[1], count = 0;
	for(int i = 1; i <= n; i ++ )
	{
		if(a[i] != e)
		{
			p.push_back({a[i - 1], count});
			count = 1;
			e = a[i];
			continue;
		}
		count ++ ;
	}
	p.push_back({a[n], count});
	
	int c = p[0].first;
	int cnt = p[0].second, d = p[0].second;
	for(auto it : p)
	{
		//cout << it.first << " " << it.second << endl;
		
		int x = it.first, y = it.second;
		if(x != c && x - c == 1)
		{
			if(y > d)
				cnt += (y - d);
			c = x;
			d = y;
		}
		else if(x != c && x - c != 1)
		{
			cnt += y;
			c = x;
			d = y;
		}
	}
	
	cout << cnt << endl;
	
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

