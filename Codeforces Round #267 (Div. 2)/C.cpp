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
const int maxn = (int) 1e5 + 5;
const int MOD = 1000000007;

using namespace std;

int n, m, k;
llong pf[5050];
llong arr[5050];
llong memo[5001][5001];
llong func(int l, int r){
    if(r >= n) return -inf;
    return pf[r] - (l ? pf[l - 1] : 0);
}
llong dp(int pos, int left){
    if(left == 0) return 0;
    if(pos >= n) return -INF;
    if(memo[pos][left] != -1) return memo[pos][left];
    llong ans = -INF;
    // ignore
    ans = max(ans, dp(pos + 1, left));
    ans = max(ans, func(pos, pos + m - 1) + dp(pos + m, left - 1));
    return memo[pos][left] = ans;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin >> n >> m >> k;
    for(int i = 0; i < n; ++i) cin >> arr[i];
    pf[0] = arr[0];
    for(int i = 1; i < n; ++i) pf[i] = pf[i - 1] + arr[i];
    memset(memo, -1, sizeof(memo));
    cout << dp(0, k) << endl;
    return 0;
}