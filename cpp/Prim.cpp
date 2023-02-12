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

const int N = 510, INF = 0x3f3f3f3f;
int g[N][N], dist[N], n, m; //�ڽӾ����� 
bool st[N]; 

int pirm()
{
	memset(dist, 0x3f, sizeof dist);
	
	int res = 0;
	for(int i = 1; i <= n; i ++ )
	{
		int t = -1;
		for(int j = 1; j <= n; j ++ ) // �����ǰ���ڼ����е����·�� 
		{
			if(!st[j] && (t == -1 || dist[t] > dist[j]))
				t = j;
		}
		
		st[t] = true;
		
		if(i != 1 && dist[t] == INF) return INF; // ����ͨ����С������ 
		if(i != 1) res += dist[t];
		
		for(int j = 1; j <= n; j ++ )
			dist[j] = min(dist[j], g[t][j]); // ά��j�����ϵ����·�� 
	}
	
	return res;
	
}

void solve()
{
	memset(g, 0x3f, sizeof g);
	cin >> n >> m;
	while(m -- )
	{
		int a, b,c;
		cin >> a >> b >> c;
		g[a][b] = g[b][a] = min(g[a][b], c); // ����ͼ 
	}
	
	int t = pirm();
	
	if(t == INF) cout << "impossible" << endl;
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

