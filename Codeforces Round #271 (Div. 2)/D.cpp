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
typedef pair<llong, llong> PI;
typedef pair<PI, llong> PII;
typedef vector<llong> VI;
typedef vector<VI> VVI;
llong INF = (1LL << 62);
const int inf = (1LL << 30);
const int maxn = (llong) 1e5 + 5;
const int MOD = 1000000007;

using namespace std;

int t, k;
int memo[1234567];
int f(int left){
    if(left == 0) return 0;
    if(memo[left] != -1) return memo[left];
    int res = 0;
    res += 1 + f(left - 1);
    if(res >= MOD) res -= MOD;
    if(left - k >= 0) res += 1 + f(left - k);
    if(res >= MOD) res -= MOD;
    return memo[left] = res % MOD;
}

int main()
{
    srand(time(NULL));
    cin >> t >> k;
    memset(memo, -1, sizeof(memo));
    f(100000);
    for(int i = 0; i < t; ++i){
        int a, b;
        cin >> a >> b;
        llong fb = f(b);
        llong fa = f(a - 1);
        cout << ((fb%MOD) - (fa%MOD) + MOD) % MOD << endl;
    }
    return 0;
}
