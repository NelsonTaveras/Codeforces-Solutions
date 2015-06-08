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

int a[150];

int main()
{
    ios_base::sync_with_stdio(false);
    // freopen("input.txt", "r", stdin);
    int n, m;
    cin >> n >> m;
    vector<llong> V(n);
    for(int i = 0; i < n; ++i) cin >> V[i];
    for(int i = 0; i < m; ++i){
        int x;
        cin >> x;
        a[x - 1] = 1;
    }
    vector<llong> V2;
    llong ans = 0;
    for(int i = 0; i < n; ++i){
        if(a[i])
            V2.push_back(V[i]);
        else
            ans += V[i];
    }
    sort(V2.begin(), V2.end());
    for(int i = m - 1; i >= 0; --i){
        if(ans >= V2[i])
            ans += ans;
        else
            ans += V2[i];
    }
    cout << ans << endl;
    return 0;
}