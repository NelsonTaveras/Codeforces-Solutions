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
#include <bitset>

using namespace std;

#define mp make_pair
typedef long long llong;
typedef pair<int, int> PII;
typedef pair<int, PII> PIP;
typedef vector<int> VI;
typedef vector<VI> VVI;

llong INF = (1LL << 62);
const int inf = (1LL << 30);
const int maxn = (llong) 1e6 + 10;
const int MOD = 1000000007;

int A[75];
int B[75];
int act[75][2][2];
int memo[75][2][2];


int dp(int bit, bool onLimitLow, bool onLimitHigh) {
    if(bit >= 70) return 0;
    if(memo[bit][onLimitLow][onLimitHigh] != -1) return memo[bit][onLimitLow][onLimitHigh];
    int res = -1000000000;
    for (int i = 0; i <= 1; ++i) {
        if (onLimitLow  && i < A[bit]) continue;
        if (onLimitHigh && i > B[bit]) continue;
        int w = i + dp(bit + 1, 
                onLimitLow  && i == A[bit],
                onLimitHigh && i == B[bit]);
        if (w > res) {
            res = w;
            act[bit][onLimitLow][onLimitHigh] = i;
        }
    }
    return memo[bit][onLimitLow][onLimitHigh] = res;
}

// 101011

llong backtrack(int bit, bool onLimitLow, bool onLimitHigh) {
    llong res = 0;
    while (bit < 70) {
        int choice = act[bit][onLimitLow][onLimitHigh];
        res = (res<<1) + choice;        
        onLimitLow = onLimitLow && choice == A[bit];
        onLimitHigh = onLimitHigh && choice == B[bit];
        bit++;
    }
    return res;
}
int main() {    
    ios_base::sync_with_stdio(false);
    int tc;
    cin >> tc;
    llong a, b;
    while (tc--) {
        cin >> a >> b;
        for (int bit = 69; bit >= 0; --bit){
            A[bit] = a & 1;
            a >>= 1;
        }
        for (int bit = 69; bit >= 0; --bit){
            B[bit] = b & 1;
            b >>= 1;
        }
        memset(memo, -1, sizeof(memo));
        dp(0, 1, 1);
        cout << backtrack(0, 1, 1) << endl;
    }
    return 0;
}
