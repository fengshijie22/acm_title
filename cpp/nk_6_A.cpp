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

void solve()
{
	LL x;
	cin >> x;
	if(x >= 1 && x <= 7) cout << "very easy" << endl;
	else if(x > 7 && x <= 233) cout << "easy" << endl;
	else if(x > 233 && x <= 10032) cout << "medium" << endl;
	else if(x > 10032 && x <= 114514) cout << "hard" << endl;
	else if(x > 114514 && x <= 1919810) cout << "very hard" << endl;
	else cout << "can not imagine" << endl; 
}

int main()
{
	IOS;
	int t = 1;
	while(t -- )
		solve();
		
	return 0;
}

