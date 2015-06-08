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
typedef unsigned long long llong;
typedef pair<llong, llong> PI;
typedef pair<PI, llong> PII;
typedef vector<llong> VI;
typedef vector<VI> VVI;
llong INF = (1LL << 62);
const int inf = (1LL << 30);
const int maxn = (llong) 1e6 + 5;
const int MOD = 1000000007;

using namespace std;

llong n, k, m;
llong acu[maxn];
llong arr[maxn];
llong check(llong want){
    memset(acu, 0, sizeof(acu));
    llong got = 0;
    llong d = 0;
    for(int i = 0; i < n; ++i){
        got += acu[i];
        if( got + arr[i] < want ){
            llong dif = want - got - arr[i];
            got += dif;
            acu[i + k] = -1 * dif;
            d += dif;
        }
    }
    return d;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin >> n >> m >> k;
    for(int i = 0; i < n; ++i) cin >> arr[i];
    llong lo = 0;
    llong hi = (llong)1e10;
    while(lo < hi){
        llong mid = lo + (hi - lo + 1) / 2;
        if(!(check(mid) <= m))
            hi = mid - 1;
        else
            lo = mid;
    }
    cout << lo << endl;
    return 0;
}
