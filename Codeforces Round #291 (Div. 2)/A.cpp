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


int main() {
    ios_base::sync_with_stdio(false);
    string S, ans;
    cin >> S;
    bool f = false;
    int sz = (int) S.size();
    for(int i = 0; i < sz; ++i){
        int d = S[i] - '0';
        int t = 9 - d;
        if(t == 0 && !f){
            ans += S[i];
            f = 1;
            continue;
        }
        f = 1;
        ans += min(t, d) + '0';
    }
    cout << ans << endl;
    return 0;
}
