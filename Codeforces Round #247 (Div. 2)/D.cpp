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

int bits[155];
llong dp[61][61][2];
llong m, k;
int highBIT;
void fill(llong n){
    for(int i = 0; i <= 60; ++i){
        bits[i] = (n & (1LL<<i)) > 0;
        if(bits[i]) highBIT = i;
    }
}
llong go(int b, int s, int f){
    if(b < 0) return s == k;
    if(dp[b][s][f] != -1) return dp[b][s][f];
    llong res = 0;
    for(int d = 0; d <= 1; ++d){
        if(d > bits[b] && f) break;
        res += go(b - 1, s + d, f && (d == bits[b]));
    }
    return dp[b][s][f] = res;
}
llong func(llong l, llong r){
    fill(r);
    memset(dp, -1, sizeof(dp));
    llong rr = go(highBIT, 0, 1);
    fill(l - 1);
    memset(dp, -1, sizeof(dp));
    llong ll = go(highBIT, 0, 1);
    return rr - ll;
}
llong bsearch(llong lo, llong hi){
    while(lo < hi){
        llong mid = lo + (hi - lo ) / 2;
        if(func(mid + 1, 2 * mid) >= m)
            hi = mid;
        else
            lo = mid + 1;
    }
    return lo;
}
int main()
{
    ios_base::sync_with_stdio(false);
    // freopen("input.txt", "r", stdin);

    cin >> m >> k;
    cout << bsearch(1, 1LL * 1e18) << endl;

    return 0;
}