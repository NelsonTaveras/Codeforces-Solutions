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

bool check(llong A){
    while(A != 0){
        int d = A % 10;
        if(d == 8) return 1;
        if(d == -8) return 1;
        A /= 10;
    }
    return 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    llong A;
    cin >> A;
    llong ans = 0;
    while(1){
        if(check(A) && ans > 0){
            cout << ans << endl;
            return 0;
        }
        ans++;
        A++;
    }
    return 0;
}
