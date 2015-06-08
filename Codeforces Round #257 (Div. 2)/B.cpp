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

llong ans[55];

/*

f1 = x
f2 = y
f3 = y - x
f4 = -x
f5 = -y
f6 = -y + x


 */


int main()
{
    ios_base::sync_with_stdio(false);
    llong x, y, n;
    cin >> x >> y >> n;
    ans[0] = x;
    ans[1] = y;
    ans[2] = y - x;
    ans[3] = -x;
    ans[4] = -y;
    ans[5] = -y + x;
    for(int i = 0; i <= 15; ++i){
        ans[i] %= 1000000007;
    }
    for(int i = 0; i <= 15; ++i){
        ans[i] += 1000000007;
    }
    for(int i = 0; i <= 15; ++i){
        ans[i] %= 1000000007;
    }
    --n;
    cout << ans[n % 6] << endl;
    return 0;
}
