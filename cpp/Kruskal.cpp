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

const int N = 2e5 + 10;
int p[N], n, m; // 并查集 

struct Edgs // 结构体存图 
{
	int a, b, w;
}edgs[N];

bool cmp(Edgs x, Edgs y) // sort里的cmp排序 
{
	return x.w < y.w;
}

int find(int x) // 并查集find操作 
{
	if(p[x] != x) p[x] = find(p[x]);
	return p[x];
}

void solve()
{
	cin >> n >> m;
	for(int i = 1; i <= m; i ++ )
	{
		int a, b, w;
		cin >> a >> b >> w;
		edgs[i] = {a, b, w};
	}
	
	sort(edgs + 1, edgs + m + 1, cmp); // 按权重排序 
	
	for(int i = 1; i <= n; i ++ ) p[i] = i; // 并查集初始化 
	
	int res = 0, cnt = 0;
	for(int i = 1; i <= m; i ++ )
	{
		int a = edgs[i].a, b = edgs[i].b, w = edgs[i].w;
		
		a = find(a), b = find(b);
		
		if(a != b) // a, b不在同一个并查集中 就将它们加在同一并查集中 
		{
			p[a] = b;
			res += w;
			cnt ++ ;
		}
	}
	
	if(cnt < n - 1) cout << "impossible" << endl; // 操作的边小于n - 1 就代表所有点不是连通的 
	else cout << res << endl;
	
}

int main()
{
	IOS;
	int t = 1;
	while(t -- )
		solve();
		
	return 0;
}

