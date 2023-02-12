#include <iostream>
#include <cstring>
#include <algorithm>
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

void solve()
{
	string s, t;
	bool pd = false;
	cin >> s >> t;
	if(s.size() != t.size())
	{
		if(t.size() > s.size())
		{
			pd = true;
			swap(s, t);
		}
		set<char> ft;
		for(int i = 0; i < s.size() - t.size(); i ++ )
			ft.insert(s[i]);
		if(ft.size() > 1)
		{
			cout << (pd ? "<" : ">") << endl;
			return ;
		}
        string cs;
		for(int i = s.size() - t.size(); i < s.size(); i ++ )
			cs += s[i];
		for(int i = 0; i < t.size(); i ++ )
		{
			if(cs[i] != t[i])
			{
				if(t[i] == s[0])
				{
					cout << (pd ? "<" : ">") << endl;
					return ;
				}
				break;
			}
		}
		cout << "!" << endl;
	}
	else
	{
		if(s == t) cout << "=" << endl;
		else cout << "!" << endl;
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

