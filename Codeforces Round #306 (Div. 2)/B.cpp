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

llong arr[20];

int main(){
    ios_base::sync_with_stdio(false);
    llong n, l, r, x;
    cin >> n >> l >> r >> x;
    llong ans = 0;
    for(int i = 0; i < n; ++i) cin >> arr[i];
    for(int i = 0; i < (1<<n); ++i){
        int cnt = __builtin_popcount(i);
        if(cnt < 2) continue;
        llong hardest = -inf;
        llong easiest = inf;
        llong sum = 0;
        for(int j = 0; j < n; ++j){
            if(i & (1<<j)){
                llong d = arr[j];
                hardest = max(hardest, d);
                easiest = min(easiest, d);
                sum += d;
            }
        }
        if(l <= sum && sum <= r){
            if((hardest - easiest) >= x){
                ans++;
            }
        }
    }
    cout << ans << endl;
    return 0;
}
