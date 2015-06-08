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
const int maxn = (int) 3e5 + 5;
const int MOD = 1000000007;

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    VVI a, b;
    a = VVI(n + 1);
    b = VVI(n + 1);
    int ma = 0;
    for(int i = 0; i < n; ++i){
        // price, quality
        int aa, bb;
        cin >> aa >> bb;
        a[aa].push_back(aa);
        b[aa].push_back(bb);
        ma = max(ma, aa);
    }
    int mi = inf;
    for(int i = 0; i < b[ma].size(); ++i){
        mi = min(mi, b[ma][i]);
    }
    for(int i = ma - 1; i >= 0; --i){
        int tmi = inf, tma = 0;
        for(int j = 0; j < b[i].size(); ++j){
            tmi = min(tmi, b[i][j]);
            tma = max(tma, b[i][j]);
        }
        if(tma > mi){
            cout << "Happy Alex" << endl;
            return 0;
        }
        mi = min(mi, tmi);
    }
    cout << "Poor Alex" << endl;
    return 0;
}
