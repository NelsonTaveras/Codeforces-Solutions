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
typedef pair<llong, llong> PI;
typedef pair<PI, llong> PII;
typedef vector<llong> VI;
typedef vector<VI> VVI;
llong INF = (1LL << 62);
const llong inf = (1LL << 30);
const llong maxn = (llong) 1e6 + 10;
const llong MOD = 1000000007;


int main() {
    ios_base::sync_with_stdio(false);
    int a, b, c;
    cin >> a >> b >> c;
    int ma = 0;
    ma = max(ma, a*b*c);
    ma = max(ma, (a+b) * c);
    ma = max(ma, (a) * (b + c));
    ma = max(ma, (a + b + c));
    cout << ma << endl;
    return 0;
}
