#include <iostream>
#include <cmath>
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
const int inf = (1LL<<30);
const int maxn = (int) 1e9 + 5;

int main()
{
    ios_base::sync_with_stdio(false);
    // freopen("input.txt", "r", stdin);

    int n, m;
    cin >> n >> m;
    VI V(n);
    for(int i = 0; i < n; ++i) cin >> V[i];
    int res = 0;
    int cur = 0;
    int cnt = 0;
    while(cur < n){
        if(cnt + V[cur] <= m){
            cnt += V[cur];
            cur++;
        }else{
            cnt = 0;
            res++;
        }
    }
    cout << res + 1 << endl;
    return 0;
}