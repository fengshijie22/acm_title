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
#define IOS ios::sync_with_stdio(false); \
            cin.tie(0);              \
            cout.tie(0);
using namespace std;

typedef long long LL;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;
const int INF = 0x3f3f3f3f;
const LL INFL = 0x3f3f3f3f3f3f3f3f;

void solve()
{
	int n;
	cin >> n;
	string s;
	cin >> s;
	int j = 1;
	bool pd = false;
	if (s[0] != 'm' && s[0] != 'M') {
		cout << "NO" << endl;
		return ;
	}

	for (int i = 1; i < s.size(); i ++ ) {
		if (j == 1 && (s[i - 1] == 'm' || s[i - 1] == 'M') && (s[i] == 'e' || s[i] == 'E')) {
			j ++ ;
			continue;
		}
		if (j == 2 && (s[i - 1] == 'e' || s[i - 1] == 'E') && (s[i] == 'o' || s[i] == 'O')) {
			j ++ ;
			continue;
		}		
		if (j == 3 && (s[i - 1] == 'o' || s[i - 1] == 'O') && (s[i] == 'w' || s[i] == 'W')) {
			j ++ ;
			continue;
		}
		if (j == 4 && (s[i] != 'w' && s[i] != 'W')) {
			pd = true;
			break;
		}
		if (j == 3 && (s[i] != 'o' && s[i] != 'O')) {
			pd = true;
			break;
		}
		if (j == 2 && (s[i] != 'e' && s[i] != 'E')) {
			pd = true;
			break;
		}
		if (j == 1 && (s[i] != 'm' && s[i] != 'M')) {
			pd = true;
			break;
		}

		if (s[i] != 'e' && s[i] != 'E' && s[i] != 'm' && s[i] != 'M' && s[i] != 'o' && s[i] != 'O' && s[i] != 'w' && s[i] != 'W') {
			pd = true;
			break;
		}
	}

	if (j != 4 || pd) {
		cout << "NO" << endl;
	}
	else {
		cout << "YES" << endl;
	}

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
