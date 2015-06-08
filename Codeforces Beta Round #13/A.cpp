#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <cstdlib>
#include <map>
#include <ctime>
#include <set>
#include <algorithm>
#include <cstring>
#include <queue>
#include <stack>
#include <sstream>
#include <cstdio>

using namespace std;

#define mp make_pair
typedef long long llong;
typedef unsigned long long ullong;
typedef pair<int, int> PI;
typedef pair<PI, int> PII;
typedef vector<int> VI;
typedef vector<VI> VVI;
llong INF = (1LL<<62);
const int inf = (1LL<<30);
const int maxn = (int) 1e5 + 5;
const int MOD = 1000000007;

int func(int n, int b)
{
	VI V;
	while(n >= b)
	{
		V.push_back((int)n%b);
		n /= b;
	}
	if(n >= 0) V.push_back(n);
	int s = 0;
	for(int i = 0; i < V.size(); ++i) s += V[i];
//	cout << n << ' ' << b << " - > ";
//	for(int i = 0; i < V.size(); ++i)
//		cout << V[i] << ' ';
//	cout << endl;
	return s;
}

int main()
{
	ios_base::sync_with_stdio(false);
	func(5, 4);
	int n;
	cin >> n;
	int ans = 0;
	int cnt = 0;
	for(int i = 2; i <= n - 1; ++i)
		ans += func(n, i), cnt++;
	cout << ans/__gcd(ans, cnt) << '/' << cnt/__gcd(ans, cnt) << endl;
	return 0;
}
