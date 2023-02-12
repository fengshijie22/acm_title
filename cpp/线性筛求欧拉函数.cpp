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

const int N = 1e6 + 10;
LL prime[N], phi[N], cnt = 0;
bool st[N];

// N的欧拉函数 = N(1 - 1 / p1)(1 - 1 / p2) ··· (1 - 1 / pk);
// p1, p2, p3, ··· , pk 为N的质因数

LL get_oula(int n) // 求欧拉函数
{
    phi[1] = 1; // 1的欧拉函数是1
    for(int i = 2; i <= n; i ++ ) // 线性筛
    {
        if(!st[i]) prime[cnt ++ ] = i, phi[i] = i - 1; // 如果是质数就存储， 质数的欧拉函数是质数减一
        for(int j = 0; prime[j] <= n / i; j ++ ) // 遍历质数
        {
            st[prime[j] * i] = true; // 用最小质因数prime[j]筛掉prime[j] * i
            if(i % prime[j] == 0) // 如果i是prime[j]的倍数prime[j] * i将不是由最小质因数筛掉
            {
                phi[prime[j] * i] = phi[i] * prime[j]; // prime[j] * i的欧拉函数是phi[i] * prime[j];
                                                       // i % prime[j] == 0; phi[i] 中乘了(1 - 1 / prime[j])
                                                       // phi[prime[j] * i] = phi[i] * prime[j];
                break;
            }
            phi[prime[j] * i] = phi[i] * (prime[j] - 1); // prime[j] * i的欧拉函数是phi[i] * (prime[j] - 1)
                                                         // i % prime[j] != 0; phi[i]中没有乘(1 - 1 / prime[j]);
                                                         // phi[prime[j] * i] = phi[i] * prime[j] * (1 - 1 / prime[j])
                                                         // phi[prime[j] * i] = phi[i] * (prime[j] - 1);
        }
    }
    
    LL res = 0;
    for(int i = 1; i <= n; i ++ ) // 求和
        res += phi[i];
    return res;
}

void solve()
{
	int n;
	cin >> n;
	LL res = get_oula(n);
	
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

