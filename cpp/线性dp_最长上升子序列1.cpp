#include <iostream>
#include <cstdio>
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

typedef long long LL;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;
const int INF = 0x3f3f3f3f;
const LL INFL = 0x3f3f3f3f3f3f3f3f;

const int N = 1010;
int a[N], dp[N];
int n;

void solve()
{
    cin >> n;
    for(int i = 1; i <= n; i ++ )
        cin >> a[i];
    
    for(int i = 1; i <= n; i ++ )
        dp[i] = 1;

    for(int i = 1; i <= n; i ++ )
        for(int j = 0; j < i; j ++ )
            if(a[j] < a[i])
                dp[i] = max(dp[i], dp[j] + 1);
    int res = 0;
    for(int i = 1; i <= n; i ++ )
        res = max(res, dp[i]);
    cout << res << endl;
}

int main()
{
    IOS;
    int t = 1;
    while(t -- )
        solve();
        
    return 0;
}