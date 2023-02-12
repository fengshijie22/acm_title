#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

typedef long long LL;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;
const int N = 1e3 + 10;
LL a[N], b[N];
LL n, m;

bool cmp(int x, int y)
{
	return x > y;
}

bool check(int k)
{
	for(int i = 1; i <= n; i ++ )
		b[i] = a[i];
	
	sort(b + 1, b + k + 1, cmp);	
	
	LL tmp = m;
	for(int i = 1; i < k; i += 2)
		tmp -= b[i];
		
	if(k % 2 == 1)
		tmp -= b[k];
	
	if(tmp >= 0) return true;
	else return false;
	
}

void solve()
{
	cin >> n >> m;
	
	for(LL i = 1; i <= n; i ++ )
		cin >> a[i];
	
	LL l = 1, r = n;
	while(l < r)
	{
		LL mid = (l + r + 1) >> 1;
		if(check(mid)) l = mid;
		else r = mid - 1;
	}
	
	if(check(l)) cout << l << endl;
	else cout << 0 << endl;
	
}

int main()
{
	int t = 1;
	while(t -- )
		solve();
		
	return 0;
}

