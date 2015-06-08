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

#define mp make_pair7
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

VVI adj, cost;
int mat[2345][2345];
int gmat[2345][2345];
int vis[2345];
struct Edge {
    int u, v, c;
    Edge(int _u, int _v, int _c) {
        u = _u;
        v = _v;
        c = _c;
    }
    bool operator <(Edge e) const {
        if (c != e.c)
            return c < e.c;
        return u < e.u;
    }
};
int P[2345];
int SZ;
int find(int x) {
    return P[x] == x ? x : P[x] = find(P[x]);
}
bool join(int x, int y) {
    x = find(x);
    y = find(y);
    if (x != y) {
        P[x] = y;
        return true;
    }
    return false;
}
void dfs(int u, int d, int src) {
    if (vis[u])
        return;
    vis[u] = 1;
    gmat[src][u] = d;
    for (int i = 0; i < adj[u].size(); ++i) {
        int v = adj[u][i];
        int c = cost[u][i];
        dfs(v, d + c, src);
    }
}
int main() {
    int N;
    scanf("%d", &N);
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j) {
            scanf("%d", &mat[i][j]);
            if (i == j && mat[i][j] > 0) {

                cout << "NO" << endl;
                return 0;
            }
            if (i != j && mat[i][j] == 0) {
                cout << "NO" << endl;
                return 0;
            }
        }
    vector<Edge> V;
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            V.push_back(Edge(i, j, mat[i][j]));
    for (int i = 0; i <= N; ++i)
        P[i] = i;
    sort(V.begin(), V.end());
    adj = VVI(N);
    cost = VVI(N);
    SZ = N;
    for (int i = 0; i < V.size(); ++i) {
        int u = V[i].u;
        int v = V[i].v;
        int c = V[i].c;
        if (join(u, v)) {
            SZ--;
            adj[u].push_back(v);
            adj[v].push_back(u);
            cost[u].push_back(c);
            cost[v].push_back(c);
        }
    }
    if (SZ != 1) {
        cout << "NO" << endl;
        return 0;
    }
    for (int i = 0; i < N; ++i) {
        memset(vis, 0, sizeof(vis));
        dfs(i, 0, i);
    }
    int f = 1;
    for(int i = 0; i < N && f; ++i){
        for(int j = 0; j < N && f; ++j){
            f = (mat[i][j] == gmat[i][j]);
        }
    }
    cout << (f ? "YES" : "NO") << endl;
    return 0;
}
