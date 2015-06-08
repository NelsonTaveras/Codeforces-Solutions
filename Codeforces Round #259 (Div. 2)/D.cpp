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

int a[150];
int p[150];
bool prime(int x)
{
    for(int i = 2; i * i <= x; ++i)
        if(x % i == 0)
            return false;
    return true;
}
VI fact(int x)
{
    int d = 2;
    VI res;
    while(x > 1){
        int e = 0;
        while(x % d == 0){
            x /= d;
            e++;
        }
        if(e) res.push_back(d);
        d++;
    }
    return res;
}
int n;
int memo[110][1<<18];
int act[110][1<<18];
int pmask[65];
VVI adj;
int dp(int p, int mask)
{
    if(p >= n) return 0;
    if(memo[p][mask] != -1) return memo[p][mask];
    int res = inf;
    for(int i = 1; i <= 60; ++i){
        if(pmask[i] & mask) continue;
        int w = abs(a[p] - i) + dp(p + 1, mask | pmask[i]);
        if( w < res ){
            res = w;
            act[p][mask] = i;
        }
    }
    return memo[p][mask] = res;
}
void doit(int p, int mask){
    while(p < n){
        if(p > 0) cout << ' ';
        int choice = act[p][mask];
        cout << choice;
        p++;
        mask |= pmask[choice];
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> a[i];
    memset(p, -1, sizeof(p));
    int cur = 0;
    adj = VVI(65);
    for(int i = 2; i <= 60; ++i)
        if(prime(i))
            p[i] = cur++;
    for(int i = 1; i <= 60; ++i){
        adj[i] = fact(i);
    }
    for(int i = 1; i <= 60; ++i)
        for(int j = 0; j < adj[i].size(); ++j){
            int factor = adj[i][j];
            pmask[i] |= (1<<p[factor]);
        }
    memset(memo, -1, sizeof(memo));
    dp(0, 0);
    doit(0, 0);
    return 0;
}
