#include <iostream>
#include <cstring>
#include <algorithm>
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

const int N = 1e5 + 10;
LL c[N], a[N], b[N];
LL n, m, inv2;

LL K_pow(LL a, LL b)
{
	LL res = 1;
	while(b)
	{
		if(b & 1) res = res * a % m;
		a = a * a % m;
		b >>= 1;
	}
	return res;
}

LL inv(int x)
{
	return K_pow(x, m - 2);
}

bool check()
{
	for(int i = 1; i <= n; i ++ )
	{
		if(c[i] != c[n - i + 1]) return false;
	}
	return true;
}

void solve()
{
	cin >> n >> m;
	for(int i = 1; i <= n; i ++ )
		cin >> c[i];
		
	if(m == 2)
	{
		if(check())
		{
			cout << "YES" << endl;
			for(int i = 1; i <= n; i ++ )
				cout << c[i] << " ";
			cout << endl;
			for(int i = 1; i <= n; i ++ )
				cout << 0 << " ";
			cout << endl;
		}
		else
			cout << "NO" << endl;
	}
	else
	{
		inv2 = inv(2);
		for(int i = 1; i <= n; i ++ )
		{
			a[i] = (c[i] + c[n - i + 1]) * inv2 % m;
			b[i] = (c[i] + m - c[n - i + 1]) * inv2 % m;
		}
		cout << "YES" << endl;
		for(int i = 1; i <= n; i ++ )
			cout << a[i] << " ";
		cout << endl;
		for(int i = 1; i <= n; i ++ )
			cout << b[i] << " ";
		cout << endl;
	}
	
}

int main()
{
	IOS;
	int t = 1;
	while(t -- )
		solve();
		
	return 0;
}

