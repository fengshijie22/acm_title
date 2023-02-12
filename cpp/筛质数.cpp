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

const int N = 1e6 + 10;
int primes[N], cnt = 0, n;
bool st[N];

void get_primes() // 朴素做法 
{
	for(int i = 2; i < n; i ++ )
	{
		if(!st[i]) primes[cnt ++ ] = i;
		for(int j = i + i; j <= n; j += i)
			st[j] = true;
	}
}

void get_primes1() // 埃氏筛 
{
	for(int i = 2; i <= n; i ++ )
	{
		if(!st[i])
		{
			primes[cnt ++ ] = i;
			for(int j = i + i; j <= n; j += i)
				st[j] = true;
		}
	}
}

void get_primes2() // 线性筛 
{
	for(int i = 2; i <= n; i ++ )
	{
		if(!st[i]) primes[cnt ++ ] = i;
		for(int j = 0; primes[j] <= n / i; j ++ )
		{
			st[primes[j] * i] = true;
			if(i % primes[j] == 0)
				break;
		}
	}
}

void solve()
{
	cin >> n;
	
	get_primes2();
	
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

