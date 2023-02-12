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

set<PII> a, b;
vector<PII> lra, lrb;

void work(set<PII> &c, PII lr, int &t)
{
	c.insert(lr);
	PII be = (*c.begin());
	while(be.first <= t)
	{
		t = max(t, be.second + 1);
		c.erase(c.begin());
		if(!c.size()) return ;
		be = (*c.begin());
	}
}

void solve()
{
	int n;
	cin >> n;
	for(int i = 1; i <= n; i ++ )
	{
		int l, r;
		cin >> l >> r;
		lra.push_back({l, r});
	}
	for(int i = 1; i <= n; i ++ )
	{
		int l, r;
		cin >> l >> r;
		lrb.push_back({l, r});
	}
	int ta = 1, tb = 1;
	for(int i = 1; i <= n; i ++ )
	{
		work(a, lra[i - 1], ta);
		work(b, lrb[i - 1], tb);
		if(ta > tb)
			cout << "sa_win!" << endl;
		else if(ta < tb)
			cout << "ya_win!" << endl;
		else
			cout << "win_win!" << endl;
		cout << abs(ta - tb) << endl;
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

