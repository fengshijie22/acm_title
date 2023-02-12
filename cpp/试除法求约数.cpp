#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#define IOS ios::sync_with_stdio(0); \
			cin.tie(0);              \
			cout.tie(0);
using namespace std;

typedef long long LL;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;

vector<int> get_divisors(int n)
{
	vector<int> res;
	for(int i = 1; i <= n / i; i ++ )
	{
		if(n % i == 0)
		{
			res.push_back(i);
			if(i != n / i)
				res.push_back(n / i);
		}
	}
	
	sort(res.begin(), res.end());
	return res;
	
}

void solve()
{
	int n;
	cin >> n;
	
	while(n -- )
	{
		int x;
		cin >> x;
		
		auto res = get_divisors(x);
		
		for(auto t : res) cout << t << " ";
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

