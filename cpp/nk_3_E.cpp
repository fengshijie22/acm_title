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

void solve()
{
	double xa, ya, xb, yb;
	cin >> xa >> ya >> xb >> yb;
	
	double xm = ((xa + xb) * 1.0) / 2.0;
	double ym = ((ya + yb) * 1.0) / 2.0;
	
	double xc = xm + ym - ya;
	double yc = xa + ym - xm;
	
	int xc1 = xc, yc1 = yc;
	if(xc == xc1 && yc1 == yc)
		cout << xc1 << " " << yc1 << endl;
	else
		cout << "No Answer!" << endl;
	
}

int main()
{
	IOS;
	int t = 1;
	while(t -- )
		solve();
		
	return 0;
}

