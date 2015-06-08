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
llong INF = (1LL<<62);
const int inf = (1LL<<30);
const int maxn = (int) 1e5 + 5;
const int MOD = 1000000007;

VVI adj, cost;
VVI adjTrain, costTrain;
llong dist[maxn];
llong fre[maxn];
bool seen[maxn];
void dijkstra()
{
    priority_queue< pair<llong, int>, vector< pair<llong, int> >, greater< pair<llong, int> > > PQ;
    dist[0] = 0;
    PQ.push(mp(0, 0));
    
    while(!PQ.empty())
    {
        pair<llong, int> p = PQ.top();
        PQ.pop();
        llong d = p.first;
        int u = p.second;
        if(d > dist[u]) continue;
        for(int i = 0; i < adj[u].size(); ++i){
            int v = adj[u][i];
            llong c = cost[u][i];
            if(dist[v] > d + c){
                dist[v] = d + c;
                PQ.push(mp(dist[v], v));
            }
        }
        for(int i = 0; i < adjTrain[u].size(); ++i){
            int v = adjTrain[u][i];
            llong c = costTrain[u][i];
            if(dist[v] > d + c){
                dist[v] = d + c;
                PQ.push(mp(dist[v], v));
            }
        }
        // cout << u << ' ' << d << endl;
    }
}

int main()
{
    // freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    int n, m, k;
    cin >> n >> m >> k;
    adj = VVI(n + 1);
    cost = VVI(n + 1);
    adjTrain = VVI(n + 1);
    costTrain = VVI(n + 1);
    for(int i = 0; i < m; ++i){
        int u, v, x;
        cin >> u >> v >> x;
        --u, --v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        cost[u].push_back(x);
        cost[v].push_back(x);
    }
    for(int i = 0; i < k; ++i){
        int s, y;
        cin >> s >> y;
        --s;
        fre[s]++;
        adjTrain[0].push_back(s);
        costTrain[0].push_back(y);
        adjTrain[s].push_back(0);
        costTrain[s].push_back(y);
    }
    for(int i = 0; i <= n; ++i) dist[i] = INF;
    dijkstra();
    int cnt = 0;

    for(int i = 0; i < adjTrain[0].size(); ++i){
        
        int v = adjTrain[0][i];
        if(seen[v]) continue;
        seen[v] = 1;
        llong c = costTrain[0][i];
        int f = 0;
        for(int j = 0; j < adj[v].size() && !f; ++j){

            llong mid = adj[v][j];
            llong costMid = cost[v][j];

            if(dist[mid] + costMid == dist[v]) f = 1;
        }
        if(f) 
            cnt += fre[v];
        else
            cnt += fre[v] - 1;
        // for(int j = 0; j < adjTrain[v].size() && !f; ++j){
        //  if(i == j) continue;
        //  llong mid = adjTrain[v][j];
        //  llong costMid = adjTrain[v][j];

        //  if(dist[mid] + costMid == dist[v]) f = 1;
        // }
        // if(f) cnt++;
    }
    cout << cnt << endl;
    return 0;
}
