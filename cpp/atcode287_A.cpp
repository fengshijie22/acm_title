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
	int cnt1 = 0, cnt2  = 0;
	for(int i = 1; i <= n; i ++ )
	{
		string s;
		cin >> s;
		if(s == "For")
			cnt1 ++ ;
		else
			cnt2 ++ ;
	}
	if(cnt1 > cnt2) cout << "Yes" << endl;
	else cout << "No" << endl;	
}

int main()
{
	IOS;
	int t = 1;
	while(t -- )
		solve();
		
	return 0;
}

