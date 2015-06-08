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

using namespace std;

#define mp make_pair
typedef long long llong;
typedef unsigned long long ullong;
typedef pair<int, int> PII;
typedef pair<int, PII> PIP;
typedef vector<int> VI;
typedef vector<VI> VVI;
const int INF = (int) 1e9;
VVI adj;
int MX = -1;
int MXid;
int vis[10005];
void dfs(int u, int d)
{
    if(d > MX)
    {
        MX = d;
        MXid = u;
    }
    vis[u] = 1;
    for(int i = 0; i < adj[u].size(); ++i)
    {
        int v = adj[u][i];
        if(!vis[v]){
            vis[v] = 1;
            dfs(v, d + 1);
        }
    }
}
int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int N;
    cin >> N;
    adj = VVI(N);
    int ANS = 0;
    while(N--)
    {
        int V;
        cin >> V;
        adj = VVI(V);
        for(int i = 0; i < V - 1; i++)
        {
            int u, v;
            cin >> u >> v;
            u--, v--;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        MX = -1;
        memset(vis, 0, sizeof(vis));
        dfs(0, 0);
        memset(vis, 0, sizeof(vis));
        MX = -1;
        dfs(MXid, 0);
        ANS += MX;
    }
    cout << ANS;
}   
