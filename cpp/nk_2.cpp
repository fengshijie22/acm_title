#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;

typedef long long LL;


void solve()
{
	LL n, l, r;
	cin >> n >> l >> r;
	LL x = sqrt(n);
	LL mn = n / l + l - 1;
	LL p = l;
	if(mn > (n / r + r - 1));
	{
		p = r;
		mn = (n / r + r - 1);
	}
	
	if(x >= l && x <= r && mn > (n / x + x - 1))
	{
		p = x;
		mn = n / x + x - 1;
	}
	x ++ ;
	if(x >= l && x <= r && mn > (n / x + x - 1))
	{
		p = x;
		mn = n / x + x - 1;
	} 
	
	LL li = l, ri = p;
	while(li < ri)
	{
		LL mid = (li + ri) / 2;
		if(n / mid + mid - 1 <= mn) ri = mid;
		else li = mid + 1; 
	} 
	
	cout << li << endl;
	
}

int main()
{
	int t;
	cin >> t;
	while(t -- )
		solve(); 

	return 0;
}
