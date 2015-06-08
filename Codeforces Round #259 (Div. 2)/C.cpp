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

double func(double a, int b)
{
    if(b == 0) return 1.0;
    if(b == 1) return a;
    double ret = func(a, b / 2);
    ret *= ret;
    if(b & 1) ret *= a;
    return ret;
}

int main() {
    int n, m;
    cin >> m >> n;
    double p = 0;
    for(int i = 1; i <= m; ++i){
        p += i * ( func(1.0 * i/m, n) - func(1.0 * (i - 1) / m, n) );
    }
    printf("%.8lf\n", p);
    return 0;
}
