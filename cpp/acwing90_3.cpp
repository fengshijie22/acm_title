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

const int N = 55;
int ne[N];

void solve()
{
    int n, k;
    cin >> n >> k;
    string a;
    cin >> a;
    ne[0] = -1;
    int j = -1;

    for(int i = 1; i < n; i ++ ) {
    	while(j != -1 && a[i] != a[j + 1]) {
    		j = ne[j];
    	}

    	if(a[i] == a[j + 1]) {
    		j ++ ;
    	}
    	ne[i] = j;
	}

	for(int i = 0; i < n; i ++ ) {
		ne[i] ++ ;
	}

	if(ne[n - 1] == 0) {
		for(int i = 1; i <= k; i ++ )
			cout << a;
		cout << endl;
	}

	else {
		cout << a;
		for(int i = 1; i < k; i ++ ) {
			for(int j = ne[n - 1]; j < n; j ++ ) {
				cout << a[j];
			}
		}
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
