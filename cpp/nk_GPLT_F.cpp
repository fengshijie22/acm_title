#include <iostream>
#include <cstdio>
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
#define IOS ios::sync_with_stdio(false); \
            cin.tie(0);              \
            cout.tie(0);
using namespace std;

typedef long long LL;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;
const int INF = 0x3f3f3f3f;
const LL INFL = 0x3f3f3f3f3f3f3f3f;

const int N = 1e6 + 10, M = 2e6 + 10;
LL h[N], e[M], ne[M], w[N], idx;
LL dist[N], cnt[N];
bool st[N];
queue<LL> q;
LL n, m;

void add(LL a, LL b, LL c)
{
	e[idx] = b, ne[idx] = h[a], w[idx] = c, h[a] = idx ++ ;
}

void bfs()
{
	memset(dist, 0x3f, sizeof dist);
	
	q.push(1);
	dist[1] = 0;
	st[1] = true;

	LL cr = 1;
	while (1) 
	{
		LL s = q.size();
		LL id = 0;
        cr ++ ;
		for (LL c = 1; c <= s; c ++ )
		{
			LL t = q.front();
			q.pop();
			for (LL i = h[t]; i != -1; i = ne[i]) {
				LL j = e[i];
				if (!st[j])
				{
					dist[j] = min(dist[j], dist[t] + w[i]);
					cnt[id ++ ] = j;
				}
			}
		}
		for (LL i = 0; i < id; i ++ )
		{
			if (!st[cnt[i]])
			{
				q.push(cnt[i]);
				st[cnt[i]] = true;
			}
			if (cnt[i] == n)
			{
				cout << cr << " " << dist[n] << endl;
				return ;
			}
		}
	}
 
}

void solve()
{
	memset(h, -1, sizeof h);
	cin >> n >> m;
	while (m -- ) 
	{
		LL l, r, c;
		cin >> l >> r >> c;
		add(l, r, c);
		add(r, l, c);
	}

	bfs();

}

int main()
{
    IOS;
    int t = 1;
    while(t -- )
        solve();

    return 0;
}
