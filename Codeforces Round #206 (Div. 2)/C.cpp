#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <map>
#include <set>
#include <algorithm>
#include <cstring>
#include <queue>
#include <stack>
#include <sstream>
#include <cstdio>
#include <ctime>

using namespace std;

#define MAXN (int) 100005
#define mp make_pair
typedef long long llong;
typedef unsigned long long ullong;
typedef pair<int, int> PII;
typedef pair<int, PII> PIP;
typedef vector<int> VI;
typedef vector<VI> VVI;
const int INF = (int) 2e9;

llong arr[MAXN];
llong sum[MAXN];
llong func(int l, int r)
{
	if(l == 0)
		return sum[r];
	if(l > r) return 0;
	return sum[r] - sum[l - 1];
}
int main()
{
    //freopen("input.txt", "r", stdin);
    int n, l, r, el, er;
    cin >> n >> l >> r >> el >> er;
    for(int i = 0; i < n; ++i) cin >> arr[i];
    for(int i = 1; i <= n; ++i) sum[i] = sum[i - 1] + arr[i - 1];
    llong mi = 1000000000000000000LL;
	for(int i = 0; i <= n; ++i)
	{
		int left = i;
		int right = n - i;
		llong s = 0;
		s += func(0, left) * l;
		s += func(left + 1, n) * r;
		if(abs(right - left) > 1)
			s += (left < right ? er : el) * (abs(right - left) - 1);
		mi = min(mi, s);
	}
	cout << mi << endl;
    return 0;
}