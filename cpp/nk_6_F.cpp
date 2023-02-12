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

const int N = 2e6 + 10;
int a[N], b[N]; 

bool cmp(int a, int b)
{
	return a > b;
}

int lowbit(int x)
{
	int cnt = 0;
	while(x)
	{
		if(x & 1)  cnt ++ ;
		x >>= 1;
	}
	return cnt;
}

void solve()
{
	int n, q;
	cin >> n >> q;
	priority_queue<int> p;
	int t = 0;
	for(int i = 1; i <= n; i ++ )
	{
		int x;
		cin >> x;
		p.push(x);
	}
	int cnt = 1;
	while(p.size())
	{
		int x = p.top();
		p.pop();
		x = lowbit(x);
		if(x != 1) p.push(x);
		if(p.size()) b[cnt ++ ] = p.top();
	}
	
	while(q -- )
	{
		int k;
		cin >> k;
		if(k < cnt) cout << b[k] << endl;
		else cout << 1 << endl;
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

