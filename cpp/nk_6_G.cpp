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

const int INF = 0x3f3f3f3f;
typedef long long LL;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;

const int N = 2e5 + 10;
int z[N], f[N];

bool cmp(int a, int b)
{
	return a > b;
}

void solve()
{
	int n, k, cnt1 = 1, cnt2 = 1;
	cin >> n >> k;
	for(int i = 1; i <= n; i ++ )
	{
		int a;
		cin >> a;
		if(a >= 0) z[cnt1 ++ ] = a;
		else f[cnt2 ++ ] = a;
	}
	
	sort(z + 1, z + cnt1, cmp);
	sort(f + 1, f + cnt2);
	
	LL ans = 0;
	int i = 1, j = 1;
	while(k)
	{
		if(i < cnt1 - 1 && j < cnt2 - 1 && z[i] * z[i + 1] < f[j] * f[j + 1])
		{
			ans += f[j] * f[j + 1];
			j += 2;
			k -- ;
		}
		else if(i < cnt1 - 1 && j < cnt2 - 1 && z[i] * z[i + 1] >= f[j] * f[j + 1])
		{
			ans += z[i] * z[i + 1];
			i += 2;
			k -- ;
		}
		else if(i >= cnt1 - 1 && j < cnt2 - 1)
		{
			ans += f[j] * f[j + 1];
			j += 2;
			k -- ;
		}
		else if(i < cnt1 - 1 && j >= cnt2 - 1)
		{
			ans += z[i] * z[i + 1];
			i += 2;
			k -- ;
		}
		else if(i == cnt1 - 1 && j == cnt2 - 1)
		{
			ans += z[i] * f[j]; 
		}
	}
	cout << ans << endl;
}

int main()
{
	IOS;
	int t = 1;
	while(t -- )
		solve();
		
	return 0;
}

