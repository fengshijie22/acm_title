#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <queue>
#include <deque>
#define IOS ios::sync_with_stdio(0); \
			cin.tie(0);              \
			cout.tie(0);
using namespace std;

const int INF = 0x3f3f3f3f;
typedef long long LL;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;

bool cmp(char a, char b)
{
	return a > b;
}

void solve()
{
	string s, ans, res;
	int n, k;
	cin >> n >> k >> s;
	for(int i = 0; i < n; i ++ )
	{
		char c = s[i];
		while(k && ans.size() && ans.back() < c)
		{
			res.push_back(ans.back());
			ans.pop_back();
			k -- ;
		}
		ans.push_back(c);
	}
	while(k && ans.size())
	{
		k -- ;
		res.push_back(ans.back());
		ans.pop_back();
	}
	sort(res.begin(), res.end(), cmp);
	ans += res;
	cout << ans << endl;
}

int main()
{
	IOS;
	int t = 1;
	while(t -- )
		solve();
		
	return 0;
}

