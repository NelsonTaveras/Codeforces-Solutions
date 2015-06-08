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

#define MAXN (int) 100005
#define mp make_pair
typedef long long llong;
typedef unsigned long long ullong;
typedef pair<int, int> PII;
typedef pair<int, PII> PIP;
typedef vector<int> VI;
typedef vector<VI> VVI;
const int INF = (int) 2e9;

VVI adj;
VVI cost;
map<PII, int> ti;
int t[MAXN];
int p[MAXN];
int D[MAXN];
int func(int id, int t)
{
    if(ti.count(mp(id, t)) == 0)
        return 0;
    if(ti[mp(id, t)] == t) 
        return 1;
    return abs(t - ti[mp(id, t)]) + 1;
}

int main()
{
    //freopen("input.txt", "r", stdin);
    int N, M;
    scanf("%d %d", &N, &M);
    adj = VVI(N);
    cost = VVI(N);
    for(int i = 0; i < M; ++i)
    {
        int u, v, c;
        scanf("%d %d %d", &u, &v, &c);
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
        cost[u].push_back(c);
        cost[v].push_back(c);
    }
    for(int k = 0; k < N; ++k)
    {
        int qty;
        scanf("%d", &qty);
        for(int i = 0; i < qty; ++i)
            scanf("%d", &t[i]);
        int left = 0;
        for(int i = 0; i < qty; ++i)
        {
            while(i < qty - 1 && t[i] + 1 == t[i + 1])
                i++;
            while(left <= i)
                p[left] = i, left++;
            for(int j = 0; j < qty; ++j)
                ti[mp(k, t[j])] = t[p[j]];
        }
    }
    int mi = INF;
    memset(D, 0x3f, sizeof(D));
    priority_queue<PII, vector<PII>, greater<PII> > PQ;
    PQ.push(mp(func(0, 0), 0));
    D[0] = func(0, 0);
    while(!PQ.empty())
    {
        PII p = PQ.top();
        PQ.pop();
        int d = p.first;
        int cur = p.second;
        if(cur == N - 1)
        {
            mi = d;
            break;
        }
        if(D[cur] < d) continue;
        for(int i = 0; i < adj[cur].size(); ++i)
        {
            int v = adj[cur][i];
            int c = cost[cur][i];
            int nd = d + c + (v == N - 1 ? 0 : func(v, d + c));
            if(D[v] > nd)
            {
                D[v] = nd;
                PQ.push(mp(nd, v));
            }
        }
    }
    if(mi == INF)
        printf("-1\n");
    else
        printf("%d\n", mi);
    return 0;
}