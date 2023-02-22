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

const int N = 50;
vector<string> str_two, str_three;
int cnt_two[N], cnt_three[N];

bool cmp(int a, int b) {
	return a > b;
}

void solve()
{
	string two, three;
	cin >> two >> three;
	for (int i = two.size() - 1; i >= 0; i -- ) {
		if (two[i] == '1') {
			two[i] = '0';
			str_two.push_back(two);
			two[i] = '1';
		}
		else {
			two[i] = '1';
			str_two.push_back(two);
			two[i] = '0';
		}
	}

	for (int i = three.size() - 1; i >= 0; i -- ) {
		if (three[i] == '0') {
			three[i] = '1';
			str_three.push_back(three);
			three[i] = '2';
			str_three.push_back(three);
			three[i] = '0';
		}
		else if (three[i] == '1') {
			three[i] = '0';
			str_three.push_back(three);
			three[i] = '2';
			str_three.push_back(three);
			three[i] = '1';
		}
		else {
			three[i] = '1';
			str_three.push_back(three);
			three[i] = '0';
			str_three.push_back(three);
			three[i] = '2';
		}
	}

	int count1 = 0;
	for (int i = 0; i < str_two.size(); i ++ ) {
		int res = 0;
		string s = str_two[i];
		for (int j = s.size() - 1, k = 0; j >= 0 ; j --, k ++ ) {
			res += pow(2, k) * (s[j] - '0');
		}
		cnt_two[count1 ++ ] = res;
	}

	int count2 = 0;
	for (int i = 0; i < str_three.size(); i ++ ) {
		int res = 0;
		string s = str_three[i];
		for (int j = s.size() - 1, k = 0; j >= 0; j -- , k ++ ) {
			res += pow(3, k) * (s[j] - '0');
		}
		cnt_three[count2 ++ ] = res; 
	}

	sort(cnt_two, cnt_two + count1, cmp);
	sort(cnt_three, cnt_three + count2, cmp);

	for (int i = 0; i < count1; i ++ ) {
		for (int j = 0; j < count2; j ++ ) {
			if (cnt_two[i] == cnt_three[j]) {
				cout << cnt_two[i] << endl;
				return ;
			}
		}
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
