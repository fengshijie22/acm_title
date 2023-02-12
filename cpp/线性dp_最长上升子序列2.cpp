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

const int N = 100010;
int a[N], q[N], idx = 0;
int n;

void solve()
{
    cin >> n;
    for(int i = 1; i <= n; i ++ )
        cin >> a[i];

    q[++ idx ] = a[1];
    for(int i = 2; i <= n; i ++ )
    {
        if(a[i] > q[idx]) q[++ idx ] = a[i];
        else
        {
            int l = 1, r = idx + 1;
            while(l < r)
            {
                int mid = (l + r) >> 1;
                if(q[mid] < a[i]) l = mid + 1;
                else r = mid;
            }
            q[l] = a[i];
        }
    }
    cout << idx << endl;
}

int main()
{
    IOS;
    int t = 1;
    while(t -- )
        solve();
        
    return 0;
}
