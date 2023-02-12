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
LL v[N], sum[N];

void solve()
{
	int n, q;
	cin >> n >> q;
	for(int i = 1; i <= n; i ++ )
		cin >> v[i];
	
	sort(v + 1, v + n + 1);
	
	for(int i = 1; i <= n; i ++ )
		sum[i] = sum[i - 1] + v[i];
	
	while(q -- )
	{
		LL k, x;
		cin >> k >> x;
		int l = 1, r = n;
		while(l < r)
		{
			int mid = (l + r + 1) >> 1;
			if(v[mid] > x) r = mid - 1;
			else l = mid; 
		}
		
        if(x < v[1])
        {
            cout << 0 << endl;
            continue;
        }
        
		if(k >= l)
			cout << sum[l] << endl;
		else
			cout << sum[l] - sum[l - k] << endl;
		
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

