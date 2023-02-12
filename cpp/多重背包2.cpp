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
#define IOS ios::sync_with_stdio(0); \
            cin.tie(0);              \
            cout.tie(0);
using namespace std;

typedef long long LL;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;
const int INF = 0x3f3f3f3f;
const LL INFL = 0x3f3f3f3f3f3f3f3f;

const int N = 25000, M = 2010;
int n, m;
int v[N], w[N], dp[M];

void solve()
{
    cin >> n >> m;
    int cnt = 0;
    for(int i = 1; i <= n; i ++ )
    {
    	int a, b, s, k = 1;
    	cin >> a >> b >> s;
    	cnt ++ ;
    	while(k < s)
    	{
    		cnt ++ ;
    		v[cnt] = a * k;
    		w[cnt] = b * k;
    		s -= k;
    		k *= 2;
    	}
    	if(s > 0)
    	{
    		cnt ++ ;
    		v[cnt] = a * s;
    		w[cnt] = b * s;
    	}
    }

    for(int i = 1; i <= cnt; i ++ )
    	for(int j = m; j >= v[i]; j -- )
    		dp[j] = max(dp[j], dp[j - v[i]] + w[i]);

    cout << dp[m] << endl;

}

int main()
{
    IOS;
    int t = 1;
    while(t -- )
        solve();
        
    return 0;
}
