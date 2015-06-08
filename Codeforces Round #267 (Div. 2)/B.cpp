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
llong INF = (1LL << 62);
const int inf = (1LL << 30);
const int maxn = (int) 1e5 + 5;
const int MOD = 1000000007;

using namespace std;

int mask[5500];
int func(int a, int b){
    int cnt = 0;
    for(int i = 0; i <= 25; ++i){
        int ma = (mask[a] & (1<<i)) == 0;
        int mb = (mask[b] & (1<<i)) == 0;
        cnt += (ma != mb);
    }
    return cnt;
}
int main() {
    ios_base::sync_with_stdio(false);
    int n, m, k;
    cin >> n >> m >> k;
    for(int i = 0; i <= m; ++i){
        cin >> mask[i];
    }
    int ans = 0;
    for(int i = 0; i< m; ++i){
        if(func(i, m) <= k)
            ++ans;
    }
    cout << ans << endl;
    return 0;
}