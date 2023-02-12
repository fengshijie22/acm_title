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

int bi[4];

bool check()
{
	sort(bi + 1, bi + 4);
	if(bi[1] + bi[2] > bi[3] && bi[2] + bi[3] > bi[1] && bi[1] + bi[3] > bi[2])
		return true;
	else return false;
}

void solve()
{
	int A, B, C;
	cin >> A >> B >> C;
	int a = B + C - A;
	int b = A + C - B;
	int c = A + B - C;
	if(a % 2 == 0 && b % 2 == 0 && c % 2 == 0 && a && b && c)
	{
		a /= 2; b /= 2; c /= 2;
		bi[1] = a, bi[2] = b, bi[3] = c;
		if(check())
		{
			cout << "YES" << endl;
			cout << a << " " << b << " " << c << endl;
		}
		else
			cout << "NO" << endl;
	}
	else
		cout << "NO" << endl;
}

int main()
{
	IOS;
	int t = 1;
	cin >> t;
	while(t -- )
		solve();
		
	return 0;
}

