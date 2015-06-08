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
const int maxn = (int) 1e9 + 5;
const int MOD = 1000000007;

int main()
{
    ios_base::sync_with_stdio(false);
    // freopen("input.txt", "r", stdin);
    llong n, x;
    cin >> n >> x;
    vector<llong> V(n);
    for(int i = 0; i < n; ++i) cin >> V[i];
    sort(V.begin(), V.end());
    llong ans = 0;
    for(int i = 0; i < n; ++i){
        ans += V[i] * x;
        if(x > 1) --x;
    }
    cout << ans << endl;
    return 0;
}