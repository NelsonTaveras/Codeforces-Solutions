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
typedef pair<PI, int> PII;
typedef vector<int> VI;
typedef vector<VI> VVI;
llong INF = (1LL<<62);

const int maxn = (int) 4 * 1e5 + 50;

int n, p;
int f[maxn + 3];
llong t[maxn + 3];
PI arr[maxn + 3];
void ins(int x, int v){
    x++;
    while(x < maxn){
        t[x] += v;
        x += (x & -x);
    }
}
llong get(int x){
    x++;
    llong res = 0;
    while(x > 0){
        res += t[x];
        x -= (x & -x);
    }
    return res;
}
int main()
{
    ios_base::sync_with_stdio(false);
    // freopen("input.txt", "r", stdin);
    cin >> n >> p;
    VVI adj(n + 10);
    for(int i = 0; i < n; ++i){
        int x, y;
        cin >> x >> y;
        arr[i] = mp(x, y);
        f[x]++, f[y]++;
        adj[x].push_back(i);
        adj[y].push_back(i);
    }
    llong res = 0;
    int ma = 0;
    for(int i = 1; i <= n; ++i){
        ins(f[i], 1);
        ma = max(ma, f[i]);
    }
    for(int i = 1; i <= n; ++i){
        int v = f[i];
        int k = p - v;
        if(k < 0) k = 0;

        for(int j = 0; j < adj[i].size(); ++j){
            int u = adj[i][j];
            int fv = arr[u].first;
            int sv = arr[u].second;
            ins(f[fv], -1);
            ins(f[fv] - 1, 1);
            f[fv]--;
            ins(f[sv] - 1, 1);
            ins(f[sv], -1);
            f[sv]--;
        }
        res += get(maxn - 2) - get(k - 1);
        if(v >= p) --res;
        for(int j = 0; j < adj[i].size(); ++j){
            int u = adj[i][j];
            int fv = arr[u].first;
            int sv = arr[u].second;
            f[fv]++, f[sv]++;
            ins(f[fv], 1);
            ins(f[sv], 1);
            ins(f[fv] - 1, -1);
            ins(f[sv] - 1, -1);
        }
    }
    cout << res / 2 << endl;
    return 0;
}