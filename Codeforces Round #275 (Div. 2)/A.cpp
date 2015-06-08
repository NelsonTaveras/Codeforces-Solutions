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
typedef pair<int, PI> PII;
typedef vector<int> VI;
typedef vector<VI> VVI;

llong INF = (1LL << 62);
const int inf = (1LL << 30);
const int maxn = (int) 1e5 + 10;
const int MOD = 1000000007;

int main() {
    llong l, r;
    cin >> l >> r;
    if(l & 1) l++;
    if((r - l + 1) < 3){
        cout << -1 << endl;
        return 0;
    }
    cout << l << ' ' << l + 1 << ' ' << l + 2 << endl;
    return 0;
}
