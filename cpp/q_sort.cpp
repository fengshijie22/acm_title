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

const int N = 1e6 + 10;
int a[N];

void q_sort(int l, int r)
{
	if(l >= r) return ; //排序已经完成 
	
	int i = l - 1, j = r + 1, x = a[(l + r) >> 1]; // 以x为基准，其左边小于x，右边大于x 
	while(i < j)
	{
		do{i ++ ;} while(a[i] < x);
		do{j -- ;} while(a[j] > x);
		if(i < j) swap(a[i], a[j]);
	}
	
	q_sort(l, j); // 递归左边 
	q_sort(j + 1, r); // 递归右边 
	
}

void solve()
{
	int n;
	cin >> n;
	for(int i = 1; i <= n; i ++ )
		cin >> a[i];
	
	q_sort(1, n);
	
	for(int i = 1; i <= n; i ++ )
		cout << a[i] << " ";
	
}

int main()
{
	IOS;
	int t = 1;
	while(t -- )
		solve();
		
	return 0;
}

