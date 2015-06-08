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
#include <bitset>

using namespace std;

#define mp make_pair
typedef long long llong;
typedef pair<int, int> PI;
typedef pair<PI, int> PII;
typedef vector<int> VI;
typedef vector<VI> VVI;
llong INF = (1LL << 62);
const llong inf = (1LL << 30);
const llong maxn = (llong) 1e6 + 10;
const llong MOD = 1000000007;

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    int mi = inf;
    for(int i = 0; i <= n; ++i){
        int left = n - i;
        if(left % 2 == 0){
            int s = left / 2;
            if( (s + i) % m == 0 ) mi = min(mi, s + i);
        }
    }
    if(mi == inf) mi = -1;
    cout << mi << endl;
    return 0;
}
