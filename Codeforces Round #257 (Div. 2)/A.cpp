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
const int maxn = (int) 1e6 + 5;
const int MOD = 1000000007;

int w[150];
int g[150];

int main()
{
    ios_base::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < n; ++i){
        cin >> w[i];
    }
    queue<int> Q;
    for(int i = 0; i < n; ++i) Q.push(i);
    int last = 0;
    while(!Q.empty())
    {
        int p = Q.front();
        last = p;
        Q.pop();
        g[p] += m;
        if(g[p] >= w[p]) continue;
        Q.push(p);
    }
    cout << last + 1 << endl;
    return 0;
}
