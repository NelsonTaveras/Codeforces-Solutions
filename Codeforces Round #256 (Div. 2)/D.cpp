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
const int maxn = (int) 1e6 + 5;
const int MOD = 1000000007;

llong f(llong x, llong n, llong m)
{
    llong d = x / n;
    d = min(d, m);
    return max(0LL, min((llong)x / n, m) - (d * n == x));
}
llong check(llong x, llong n, llong m, llong k)
{
    if(x > n * m) return false;
    llong cnt = 0;
    for(int i = 1; i <= n; ++i){
        cnt += f(x, i, m);
    }
    if(cnt >= k) return false;
    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    llong n, m, k;
    cin >> n >> m >> k;
    llong lo = 1;
    llong hi = (llong)1e15;
    while(lo < hi)
    {
        llong mid = lo + (hi - lo + 1 ) / 2;
        if(!check(mid, n, m, k))
            hi = mid - 1;
        else
            lo = mid;   
    }
    cout << lo << endl;
    return 0;
}
