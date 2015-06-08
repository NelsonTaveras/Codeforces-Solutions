#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <cstdlib>
#include <map>
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
llong INF = (1LL<<62);
const int inf = (1LL<<30);

VVI adj;
int init[100010];
int goal[100010];
int vis[100010];
int flip[100010];
void dfs(int u, int p, int level, int odd, int even){
    if(vis[u]) return ;
    vis[u] = 1;

    int fstate = init[u];
    int cur = fstate;
    int flips = (level & 1) ? odd : even;
    if(flips & 1) cur = 1 - cur;
    int flipped = cur != goal[u];
    if(flipped) flip[u] = 1;
    for(int i = 0; i < adj[u].size(); ++i){
        int v = adj[u][i];
        if(vis[v] || v == p) continue;
        
        if(level & 1)
            dfs(v, u, level + 1, odd + flipped, even);
        else
            dfs(v, u, level + 1, odd, even + flipped);
    }
}

int main(){
    // freopen("input.txt", "r", stdin);
    int n;
    cin >> n;
    adj = VVI(n);
    for(int i = 1; i < n; ++i){
        int u, v;
        cin >> u >> v;
        --u, --v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for(int i = 0; i < n; ++i) cin >> init[i];
    for(int i = 0; i < n; ++i) cin >> goal[i];
    memset(vis, 0, sizeof(vis));
    dfs(0, 0, 0, 0, 0);
    int ans = 0;
    for(int i = 0; i < n; ++i)
        if(flip[i])
            ans++;
    cout << ans << endl;
    for(int i = 0; i < n; ++i)
        if(flip[i])
            cout << i + 1 << endl;
    // cout << ans << endl;
    return 0;
}