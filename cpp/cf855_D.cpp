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
map<string, int> s;

void solve()
{
	/* MLE
	int n;
	s.clear();
	string str;
	cin >> n;
	cin >> str;

	
 	int idx = 0;
	for (int i = 0; i < n - 1; i ++ ) {
		string t = str;
		t.erase(i, 2);
		if (!s.count(t)) {
			s.insert({t, idx ++ }); 
		}
	}

	cout << s.size() << endl;
	*/

	int n, r;
	cin >> n;
	string str;
	cin >> str;
	r = n - 1;
	for (int i = 0; i < n - 2; i ++ ) {
		if (str[i] == str[i + 2]) {
			r -- ;
		}
	}

	cout << r << endl;


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
