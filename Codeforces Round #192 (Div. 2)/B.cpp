#include <cmath>
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

using namespace std;

#define mp make_pair
typedef long long llong;
typedef unsigned long long ullong;
typedef pair<int, int> PI;
typedef pair<int, PI> PII;
typedef vector<int> VI;
typedef vector<VI> VVI;
const int MAXN = 1005;
int mat[1001][1001];
int P[MAXN];
int SZ = 0;
inline int find(int x)
{
    return P[x] = ( P[x] == x ? x : find(P[x]));
}
bool unionfind(int x, int y)
{
    x = find(x);
    y = find(y);
    if( x != y )
    {
        P[x] = y;
        SZ--;
        return true;
    }
    return false;
}
struct Edge{
    int u;
    int v;
    int cost;
    Edge(int _u, int _v, int _cost)
    {
        u = _u;
        v = _v;
        cost = _cost;
    }
    bool operator < (Edge E)const{
        if(cost != E.cost)
            return cost < E.cost;
        else
            return u < E.u;
    }
};
int main()
{
    ios_base::sync_with_stdio(false);
    int N, M;
    cin >> N >> M;
    set<int> saw;
    for(int i = 1; i <= N; ++i)
        saw.insert(i);
    SZ = N;
    for(int i = 0; i < M; ++i)
    {
        int u, v;
        cin >> u >> v;
        saw.erase(u);
        saw.erase(v);
    }
    int center = *saw.begin();
    cout << N - 1 << endl;
    for(int i = 1; i <= N; ++i)
        if( i != center )
            cout << min(i, center) << ' ' << max(i, center) << endl;
    return 0;
}
