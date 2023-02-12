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

const int INF = 0x3f3f3f3f, mod = 1e9 + 7;
typedef long long LL;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;

const int N = 1e3 + 10;
LL yh[N][N], a[N];
LL jc[N];

LL q_jc(int n)
{
	LL res = 1;
	for(int i = 1; i <= n; i ++ )
		res = res * i % mod;
	return res;
}

void q_yh()
{
	int n = 1000;
	for(int  i = 1; i <= n; i ++ )
	{
		for(int j = 1; j <= i; j ++ )
		{
			if(j == 1 || j == i)
			{
				yh[i][j] = 1;
				continue; 
			}
			yh[i][j] = (yh[i - 1][j - 1] + yh[i - 1][j]) % mod;
		}
	}
}

void solve()
{
	jc[0] = 1;
	for(int i = 1; i < N; i ++ )
		jc[i] = q_jc(i);
	
	q_yh();
	
	int n;
	cin >> n;
	int l = 1, r = n, cnt = 1;
	while(l <= r)
	{
		if(l == r)
		{
			a[l] = cnt;
			break;
		}
		a[l ++ ] = cnt ++ ;
		a[r -- ] = cnt ++ ;
	}
	//cout << jc[99] << endl;
	LL res = 0;
	for(int i = 1; i <= n; i ++ )
	{
		//cout << jc[n - 1] << " " << jc[n - i - 1] <<" " << jc[i] << endl;
		//LL ans = jc[n - 1]/jc[n - i - 1]/jc[i];
		//cout << ans << " ";
		LL ans = yh[n][i] * a[i] % mod;
		res = (res + ans) % mod;
	}
	
	cout << res << endl;
	for(int i = 1; i <= n; i ++ )
		cout << a[i] << " ";
		
}

int main()
{
	IOS;
	int t = 1;
	while(t -- )
		solve();
		
	return 0;
}

