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
llong INF = (1LL << 62);
const int inf = (1LL << 30);
const int maxn = (int) 1e6 + 5;
const int MOD = 1000000007;

using namespace std;
int memo[1010];
int n, m, a, b;
int dp(int left)
{
    if(left <= 0) return 0;
    if(memo[left] != -1) return memo[left];
    int res = inf;
    res = min(res, a + dp(left - 1));
    res = min(res, b + dp(left - m));
    return memo[left] = res;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin >> n >> m >> a >> b;
    memset(memo, -1, sizeof(memo));
    cout << dp(n) << endl;
    return 0;
}
