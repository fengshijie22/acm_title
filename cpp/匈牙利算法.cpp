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

const int N = 510, M = 1e5 + 10;
int h[N], e[M], ne[M], idx;
int match[N];
bool st[N];

void add(int a, int b)
{
	e[idx] = b, ne[idx] = h[a], h[a] = idx ++ ;
}

bool find(int x)
{
	for(int i = h[x]; i != -1; i = ne[i]) // 遍历所有边 
	{
		int j = e[i];
		if(!st[j]) // 如果没有找过 
		{
			st[j] = true; // 置为找过 
			if(match[j] == 0 || find(match[j])) // 如果没有配对 或 与该女生配对的男生能找到另一个就返回true 
			{
				match[j] = x;
				return true;
			}
		}
	}
	return false; // 不可能配对就返回false 
}

void solve()
{
	// 匈牙利算法 是给定一个二分图，求最大匹配数量 
	// 假设为男女匹对 
	
	memset(h, -1, sizeof h);
	int n1, n2, m;
	cin >> n1 >> n2 >> m; // 二分图左右两边以及边数 （染色中的两种颜色）n1 为男， n2 为女 
	while(m -- )
	{
		int a, b;
		cin >> a >> b;
		add(a, b);
	}
	
	int cnt = 0;
	for(int i = 1; i <= n1; i ++ ) // 遍历所有男生 
	{
		memset(st, false, sizeof st);  // 每个女生只找一次，故每次找之前都将所有女生置为未找过 
		
		if(find(i)) // 遍历该男生所有看上的女生，即与i有关的边 能进行配对cnt加一 
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

