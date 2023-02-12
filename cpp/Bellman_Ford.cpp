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
struct Ege
{
	int a, b, w;
}edgs[M]; // 存储边 

int n, m, k;
int dist[M], backup[M]; 

int bellman_ford()
{
	memset(dist, 0x3f, sizeof dist);
	dist[1] = 0;
	for(int i = 1; i <= k; i ++ )
	{
		memcpy(backup, dist, sizeof dist); // 备份， 防止串联 
		for(int j = 1; j <= m; j ++ )
		{
			int a = edgs[j].a, b = edgs[j].b, w = edgs[j].w;
			if(dist[b] > backup[a] + w)
				dist[b] = backup[a] + w; // 更新距离 
		}
	}
	
	if(dist[n] > 0x3f3f3f3f / 2) return -0x3f3f3f; //不能写dist[n] == 0x3f3f3f3f, 可能出现n-1 -> n 为负权
												   //不能返回较小负数，可能dist[n]本身为较小负数 
	else return dist[n];
	
}

void solve()
{
	cin >> n >> m >> k;
	for(int i = 1; i <= m; i ++ )
	{
		int a, b, w;
		cin >> a >> b >> w;
		edgs[i] = {a, b, w};
	}
	
	int t = bellman_ford();
	
	if(t == -0x3f3f3f) cout << "impossible" << endl;
	else cout << t << endl;
	
}

int main()
{
	IOS;
	int t = 1;
	while(t -- )
		solve();
		
	return 0;
}

