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
    // freopen("input.txt", "r", stdin);
    llong n, m;
    cin >> n >> m;
    VI ans;
    for(int i = 0; i < n; ++i){
        int x;
        cin >> x;
        llong mi = inf;
        for(int j = 0; j < x; ++j){
            llong p;
            cin >> p;
            mi = min(mi, p);
        }
        if(mi < m) ans.push_back(i + 1);
    }
    cout << ans.size() << endl;
    for(int i = 0; i < ans.size(); ++i)
        cout << ans[i] << ' ';
    return 0;
}