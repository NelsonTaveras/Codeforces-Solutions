#include <iostream>
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
#include <ctime>
#include <cctype>
using namespace std;

#define mp make_pair
typedef long long llong;
typedef unsigned long long ullong;
typedef pair<int, int> PII;
typedef pair<int, PII> PIP;
typedef vector<llong> VI;
typedef vector<VI> VVI;
const llong INF = (llong) 1e9;
#define MOD (llong)  1000000007
const llong MAXN = 100010;

VVI adj, cost;
int l[550], r[550];
int vis[100050];
int g[100050];
int mi[550][550];
int dist[550][550];
void dfs(int u, int id){
    vis[u] = id;
    for(int i = 0; i < adj[u].size(); ++i){
        int v = adj[u][i];
        int c = cost[u][i];
        if(vis[v] == 0 && c == 0){
            dfs(v, id);
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    // freopen("input.txt", "r", stdin);
    int n, m, k;
    cin >> n >> m >> k;
    int cur = 0;
    for(int i = 0; i < k; ++i){
        int c;
        cin >> c;
        l[i] = cur;
        r[i] = cur + c - 1;
        for(int j = l[i]; j <= r[i]; ++j) g[j] = i;
        cur += c;
    }
    adj = VVI(cur + 10);
    cost = VVI(cur + 10);
    for(int i = 0; i <= k; ++i)
        for(int j = 0; j <= k; ++j)
            mi[i][j] = INF;
    for(int i = 0; i < m; ++i){
        int u, v, c;
        cin >> u >> v >> c;
        --u, --v;
        mi[g[u]][g[v]] = min(mi[g[u]][g[v]], c);
        mi[g[v]][g[u]] = min(mi[g[v]][g[u]], c);
        adj[u].push_back(v);
        adj[v].push_back(u);
        cost[u].push_back(c);
        cost[v].push_back(c);
    }
    memset(vis, 0, sizeof(vis));
    int id = 1;
    for(int i = 0; i < cur; ++i)
        if(vis[i] == 0) 
            dfs(i, id++);
    for(int i = 0; i < k; ++i){
        int f = vis[l[i]];
        for(int j = l[i] + 1; j <= r[i]; ++j){
            if(f != vis[j]){
                cout << "No";
                return 0;
            }
        }
    }
    for(int i = 0; i <= k; ++i)
        for(int j = 0; j <= k; ++j)
            dist[i][j] = INF;
    for(int i = 0; i < k; ++i)
        for(int j = 0; j < k; ++j)
            dist[i][j] = (i == j ? 0 : mi[i][j]);
    for(int K = 0; K < k; ++K)
        for(int i = 0; i < k; ++i)
            for(int j = 0; j < k; ++j)
                dist[i][j] = min(dist[i][j], dist[i][K] + dist[K][j]);
    cout << "Yes" << endl;
    for(int i = 0; i < k; ++i){
        for(int j = 0; j < k; ++j){
            if(dist[i][j] == INF) dist[i][j] = -1;
            cout << dist[i][j] << ' ';
        }
        cout << endl;
    }
    return 0;
}