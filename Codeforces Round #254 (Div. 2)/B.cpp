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
typedef vector<llong> VL;
typedef vector<VL> VVL;
llong INF = (1LL<<62);
const int inf = (1LL<<30);
const int maxn = (int) 1e5 + 10;
const int MOD = 1000000007;

int f[55][55];
int vis[55];
int n, m;
llong res = 1;
void dfs(int u){
    if(vis[u]) return ;
    vis[u] = 1;
    for(int i = 0; i < n; ++i){
        if(!vis[i] && f[u][i]){
            res *= 2;
            dfs(i);
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    vector<PI> V;
    for(int i = 0; i < m; ++i){
        int x, y;
        cin >> x >> y;
        --x, --y;
        f[x][y] = f[y][x] = 1;
        V.push_back(mp(x, y));
    }
    sort(V.begin(), V.end());
    llong ma = 1;
    for(int i = 0; i < n; ++i){
        memset(vis, 0, sizeof(vis));
        res = 1;
        dfs(i);
        for(int j = 0; j < n; ++j){
            dfs(j);
        }
        ma = max(ma, res);
    }
    cout << ma << endl;
    return 0;
}

