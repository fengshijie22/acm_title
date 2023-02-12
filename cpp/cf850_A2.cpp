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

const int N = 1e6 + 10;
int as[N], bs[N];


void solve()
{
    memset(as, 0, sizeof as);
    memset(bs, 0, sizeof bs);
    int n;
    cin >> n;
    int s = n;
    int aliw = 0, alib = 0, bobw = 0, bobb = 0;
   	int t = 1;
   	int cnt = 1, cot = 1;
   	int a = 1, b = 0;
   	while(t <= n)
    {
        if(a)
        {
            as[cot] += 1;
            as[cot + t] -= 1;
            cot += t;
            n -= t;
            t ++ ;
            cnt ++ ;
        }
        else
        {
            bs[cot] += 1;
            bs[cot + t] -= 1;
            cot += t;
            n -= t;
            t ++ ;
            cnt ++ ;
        }
        if(cnt == 2)
        {
            a = !a;
            b = !b;
            cnt = 0;
        }
    }
    if(n != 0)
    {
        if(a) as[cot] += 1;
        else bs[cot] += 1;
    }

    for(int i = 1; i <= s; i ++ )
    {
        as[i] = as[i - 1] + as[i];
        bs[i] = bs[i - 1] + bs[i];
    }

    for(int i = 1; i <= s; i ++ )
    {
        if(as[i])
        {
            if(i % 2 == 1) aliw ++ ;
            else alib ++ ;
        }
        else
        {
            if(i % 2 == 1) bobw ++ ;
            else bobb ++ ;
        }
    }

    cout << aliw << " " << alib << " " << bobw << " " << bobb << endl;

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
