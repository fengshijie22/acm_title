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

const int N = 1e5 + 10;
int n, m, p[N];

int find(int x) // 并查集核心 find操作 
{
	if(p[x] != x) p[x] = find(p[x]);
	return p[x];
}

void solve()
{
	cin >> n >> m;
	
	for(int i = 1; i <= n; i ++ ) p[i] = i; // 初始化并查集 
	
	while(m -- )
	{
		string op;
		int a, b;
		cin >> op >> a >> b;
		if(op == "M") p[find(a)] = find(b); // 合并两个并查集 
		else
		{
			if(find(a) == find(b)) cout << "Yes" << endl; // 判断并查集中是否有这两个数 
			else cout << "No" << endl;
		}
		
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

