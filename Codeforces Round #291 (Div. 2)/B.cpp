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
typedef pair<int, int> PII;
typedef pair<int, PII> PIP;
typedef vector<int> VI;
typedef vector<VI> VVI;

llong INF = (1LL << 62);
const int inf = (1LL << 30);
const int maxn = (llong) 1e6 + 10;
const int MOD = 1000000007;

int cross_product( int ax, int ay, int bx, int by, int cx, int cy ) {
   return (bx-ax)*(cy-ay) - (cx-ax)*(by-ay);
}

bool collinear( int ax, int ay, int bx, int by, int cx, int cy ) {
   return cross_product(ax, ay, bx, by, cx, cy) == 0;
}

map<PII, bool> checked;
int a[12345], b[12345];

int main() {
    ios_base::sync_with_stdio(false);
    int n, x0, y0;
    cin >> n >> x0 >> y0;
    for(int i = 0; i < n; ++i){
        cin >> a[i] >> b[i];
    }
    int ans = 0;
    for(int i = 0; i < n; ++i){
        if(checked.count(mp(a[i], b[i]))) continue;
        checked[mp(a[i], b[i])] = 1;
        ++ans;
        for(int j = 0; j < n; ++j){
            if(i != j){
                if(collinear(x0, y0, a[i], b[i], a[j], b[j])){
                    checked[mp(a[j], b[j])] = 1;
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}
