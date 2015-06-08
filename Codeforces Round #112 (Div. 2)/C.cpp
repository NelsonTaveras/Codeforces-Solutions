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
const llong inf = (1LL << 30);
const llong maxn = (llong) 1e5 + 5;
const llong MOD = 1000000007;

using namespace std;

int pf[1234567];

int low(int lo, int hi, int p) {
    while (lo < hi) {
        int mid = lo + (hi - lo) / 2;
        if (pf[mid] >= p)
            hi = mid;
        else
            lo = mid + 1;

    }
    if(pf[lo] != p) lo = -1;
    return lo;
}
int up(int lo, int hi, int p) {
    while (lo < hi) {
        int mid = lo + (hi - lo + 1) / 2;
        if (pf[mid] > p)
            hi = mid - 1;
        else
            lo = mid;
    }
    if(pf[lo] != p) lo = -1;
    return lo;
}
int main() {
    ios_base::sync_with_stdio(false);
    int k;
    cin >> k;
    string S;
    cin >> S;
    pf[0] = S[0] - '0';
    int len = (int) S.size();
    for (int i = 1; i < len; ++i)
        pf[i] = pf[i - 1] + S[i] - '0';
    pf[len] = pf[len - 1];
    int acu = 0;
    llong res = 0;
    for (int i = 0; i < len; ++i) {
        // look for k + acu
        int l = low(i, len - 1, k + acu);
        int u = up(i, len - 1, k + acu);
        if(l != -1 && u != -1) res += (u - l + 1);
        acu += S[i] - '0';
    }
    cout << res << endl;
    return 0;
}
