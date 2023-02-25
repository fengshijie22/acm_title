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

const int N = 1e5 + 10;
string ans, str;
bool pd = true;

bool dfs() {
    if (cin >> str) {
        if (str == "pair") {
            ans += str;
            ans += '<';
            if (dfs()) {
                ans += ',';
            }
            else {
                return false;
            }
            if (dfs()) {
                ans += '>';
            }
            else {
                return false;
            }
        }
        else {
            ans += str;
        }
        return true;
    }
    return false;

}

void solve() // 编译器跑不出， 在acwing上能过
{
    int n;
    cin >> n;
    pd = dfs();
    if (cin >> str) pd = false;
    if (!pd) {
        cout << "Error occurred" << endl;
    }
    else {
        cout << ans << endl;
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
