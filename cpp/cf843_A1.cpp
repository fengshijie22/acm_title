#include <iostream>
#include <cstring>
#include <algorithm>
#define IOS ios::sync_with_stdio(0); \
			cin.tie(0);              \
			cout.tie(0);
using namespace std;

typedef long long LL;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;

void solve()
{
	string s;
	cin >> s;
	int n = s.size();
	if(s[0] == s[n - 1])
	{
		cout << s[0] << " ";
		for(int i = 1; i < n - 1; i ++ )
		{
			cout << s[i]; 
		}
		cout << " " << s[n - 1] << endl;
	}
	else if(s[0] == 'a')
	{
		int i = 0;
		for(i = 0; i < n; i ++ ) if(s[i] == 'b') break;
		if(i == n - 1)
		{
			for(int j = 0; j < n - 2; j ++ )
				cout << s[j];
			cout << " " << "a b" << endl;
		}
		else
		{
			for(int j = 0; j < i; j ++ ) cout << s[j];
			cout << " ";
			for(int j = i; j < n - 1; j ++ ) cout << s[j];
			cout << " b" << endl; 
		}
	}
	else
	{
		int i = 0;
		for(i = 0; i < n; i ++ ) if(s[i] == 'a') break;
		if(i == n - 1)
		{
			cout << "b ";
			for(int j = 1; j < n - 1; j ++ ) cout << s[j];
			cout << " a" << endl;
		}
		else
		{
			for(int j = 0; j < i; j ++ ) cout << s[j];
			cout << " a ";
			for(int j = i + 1; j < n; j ++ ) cout << s[j];
			cout << endl;			
		}
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

