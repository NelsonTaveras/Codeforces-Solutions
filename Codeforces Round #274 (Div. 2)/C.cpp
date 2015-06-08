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
typedef pair<PI, llong> PII;
typedef vector<int> VI;
typedef vector<VI> VVI;
llong INF = (1LL << 62);
const int inf = (1LL << 30);
const int maxn = (llong) 1e6 + 10;
const int MOD = 1000000007;

int main() {
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<PI> V;
    for(int i = 0; i < n; ++i){
        int a, b;
        cin >> a >> b;
        V.push_back(mp(a, b));
    }
    sort(V.begin(), V.end());
    int d = min(V[0].first, V[0].second);
    for(int i = 1; i < n; ++i){
        PI p = V[i];
        int mi = min(p.first, p.second);
        if(mi >= d){
            d = mi;
        }else{
            if(p.first >= d)
                d = p.first;
            else
                d = p.second;
        }
    }
    cout << d << endl;
    return 0;
}