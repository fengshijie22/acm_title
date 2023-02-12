#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
#define IOS ios::sync_with_stdio(0); \
			cin.tie(0);              \
			cout.tie(0);
using namespace std;

typedef long long LL;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;

const int N = 1e5 + 10;
int h[N], e[N], w[N], ne[N], idx;
int n, m, dist[N];
bool st[N];

void add(int a, int b, int c)
{
	e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx ++ ;
}

int spfa()
{
	memset(dist, 0x3f, sizeof dist);
	dist[1] = 0;
	
	queue<int> q;
	q.push(1);
	
	st[1] = true;
	
	while(q.size())
	{
		int t = q.front();
		q.pop();
		
		st[t] = false;
		
		for(int i = h[t]; ~i; i = ne[i])
		{
			int j = e[i];
			if(dist[j] > dist[t] + w[i])
			{
				dist[j] = dist[t] + w[i];
				if(!st[j])
				{
					q.push(j);
					st[j] = true;
				}
			}
		}
	}
	
	if(dist[n] == 0x3f3f3f3f) return -0x3f3f3f3f;
	else return dist[n];
	
}

void solve()
{
	memset(h, -1, sizeof h);
	cin >> n >> m;
	for(int i = 1; i <= m; i ++ )
	{
		int a, b, c;
		cin >> a >> b >> c;
		add(a, b, c);
	}
	
	int t = spfa();
	
	if(t == -0x3f3f3f3f) cout << "impossible" << endl;
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

