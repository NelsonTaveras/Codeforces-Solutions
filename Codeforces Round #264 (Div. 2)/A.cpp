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
llong INF = (1LL << 62);
const int inf = (1LL << 30);
const int maxn = (int) 1e6 + 5;
const int MOD = 1000000007;

using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    int n, money;
    cin >> n >> money;
    int canbuy = 0;
    int ans = 0;
    for(int i = 0; i < n; ++i){
        int dollars, cents;
        cin >> dollars >> cents;
        int win = 0;
        if(cents > 0){
            dollars++;
            win = 100 - cents;
        }
        if(money < dollars) continue;
        canbuy++;
        ans = max(ans, win);
    }
    if(canbuy == 0) ans = -1;
    cout << ans << endl;
    return 0;
}