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
const int maxn = (int) 1e6 + 5;
const int MOD = 1000000007;

using namespace std;

int n, k;
int memo[1005];
int pos[1005][6];
int dp(int last)
{
    if(memo[last] != -1) return memo[last];
    int res = 0;
    for(int i = 1; i <= n; ++i){
        bool can = true;
        for(int j = 0; j < k && can; ++j){
            if(pos[i][j] <= pos[last][j] ) can = false;
        }
        if(can) res = max(res, 1 + dp(i));
    }
    return memo[last] = res;
}
int main() 
{
    cin >> n >> k;
    for(int i = 0; i <= k; ++i) pos[0][i] = 0;
    for(int i = 0; i < k; ++i){
        for(int j = 0; j < n; ++j){
            int x;
            cin >> x;
            pos[x][i] = j + 1;
        }
    }
    
    memset(memo, -1, sizeof(memo));
    cout << dp(0) << endl;
    return 0;
}
