#include <cmath>
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
int mod = 1000000007;
int n, k, d;
int memo[101][101];
int dp(int sum, int biggest){
    if(sum > n) return 0;
    if(sum == n) return biggest >= d;
    if(memo[sum][biggest] != -1) return memo[sum][biggest];
    int ways = 0;
    for(int i = 1; i <= k; ++i){
        ways += dp(sum + i, max(biggest, i));
        if(ways >= mod) ways -= mod;
    }
    return memo[sum][biggest] = ways % mod;
}
int main()
{
    ios_base::sync_with_stdio(false);
    // freopen("input.txt", "r", stdin);
    cin >> n >> k >> d;
    memset(memo, -1, sizeof(memo));
    cout << dp(0, 0) << endl;
    return 0;
}

