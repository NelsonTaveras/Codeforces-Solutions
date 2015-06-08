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
#include <cctype>
#include <bitset>

using namespace std;

#define mp make_pair
typedef long long llong;
typedef unsigned long long ullong;
typedef pair<llong, llong> PII;
typedef pair<llong, PII> PIP;
typedef vector<llong> VI;
typedef vector<VI> VVI;
const llong INF = (llong) 1e9;
#define MOD (llong)  1000000007
const llong MAXN = 100050;

int len;
int d[55];
int f[55];
int mo[2005];
llong memo[1<<19][101];
llong dp(int mask, int mod, int m){
    if(mask == (1<<len) - 1) return mod == 0;
    if(memo[mask][mod] != -1) return memo[mask][mod];
    llong ways = 0;
    for(int i = 0; i < len; ++i){
        if( (mask & (1<<i)) == 0){
            if(d[i] == 0 && __builtin_popcount(mask) == 0) continue;
            ways += dp(mask | (1<<i), mo[mod * 10 + d[i]], m);
        }
    }
    return memo[mask][mod] = ways;
}
int main()
{
    ios_base::sync_with_stdio(false);
    // freopen("input.txt", "r", stdin);
    int m;
    string S;
    cin >> S >> m;
    for(int i = 0; i <= 2000; ++i) mo[i] = i % m;
    len = (int) S.size();
    for(int i = 0; i < len; ++i){
        d[i] = S[i] - '0';
        f[d[i]]++;
    }
    memset(memo, -1, sizeof(memo));
    llong res = dp(0, 0, m);
    // cout << res << endl;
    for(int i = 0; i <= 9; ++i){
        llong fact = 1;
        for(int j = f[i]; j > 0; --j)
            fact *= j;
        res /= fact;
    }
    cout << res << endl;
    return 0;
}