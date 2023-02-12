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
int h[N], e[2 * N], ne[2 * N], idx;
int color[N], n, m; 

void add(int a, int b)
{
	e[idx] = b, ne[idx] = h[a], h[a] = idx ++ ;
}

bool dfs(int u, int c)// 合法返回true 不合法返回false 
{
	color[u] = c;
	for(int i = h[u]; i != -1; i = ne[i]) // 对链表进行深搜 
	{
		int j = e[i];
		if(!color[j]) // 如果当前点未染色就进行染色并判断是否合法 
		{
			if(!dfs(j, 3 - c))
				return false;
		}
		else if(color[j] == c)// 如果已经染色， 就判断相邻的这两个节点颜色是否相同 
		{
				return false;
		}
	}
	return true;
}

void solve()
{
	// 将整个图进行染色
	// 两个相邻点之间不能有相同颜色
	// 即不能出现奇数环。1 代表白， 2 代表黑
	// 奇数环: 1(1) -> 2(2) -> 3(1) -> 1(2) 两个1矛盾 所以不能出现奇数环 
	// 判断是否合法即判断是否是奇数环 
	
	memset(h, -1, sizeof h);
	cin >> n >> m;
	
	while(m -- )
	{
		int a, b;
		cin >> a >> b;
		add(a, b), add(b, a);
	}
	
	bool pd = true; // 是二分图为true 不是为false 
	for(int i = 1; i <= n; i ++ ) // 循环每个节点 
	{
		if(!color[i]) // 如果当前点未染色 
		{
			if(!dfs(i, 1)) // 进行涂色， 并判断是否合法 
			{
				pd = false;
				break;
			}
		}
	}
	
	if(pd) cout << "Yes" << endl;
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

