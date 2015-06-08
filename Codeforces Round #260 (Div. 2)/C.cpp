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
const int maxn = (llong) 1e5 + 5;
const int MOD = 1000000007;

using namespace std;

int n;
llong arr[maxn];
int nxt[maxn];
llong memo[maxn];
llong f[maxn];
llong dp(int x){
    if(x >= n) return 0;
    if(memo[x] != -1) return memo[x];
    return memo[x] = max( arr[x]*f[arr[x]] + dp( f[arr[x] + 1] ? nxt[nxt[x]] : nxt[x] ), dp(x + 1) );
}
int main() {
    ios_base::sync_with_stdio(false);
    cin >> n;
    for(int i = 0; i < n; ++i){
        cin >> arr[i];
        f[arr[i]]++;
    }
    sort(arr, arr + n);
    nxt[n - 1] = n;
    nxt[n] = n;
    for(int i = n - 2; i >= 0; --i){
        if(arr[i] == arr[i + 1])
            nxt[i] = nxt[i + 1];
        else
            nxt[i] = i + 1;
    }
    memset(memo, -1, sizeof(memo));
    cout << dp(0) << endl;
    return 0;
}
