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
    int n;
    cin >> n;
    VI V(n);
    for(int i = 0; i < n; ++i) cin >> V[i];
    int ans = 0;
    int f = 0;
    for(int i = 0; i < n; ++i){
        if(V[i]){
            if(f) ++ans;
            f = 0;
            ans++;
            while(i + 1 < n && V[i + 1] > 0){
                i++;
                ans++;
            }
            f = 1;
        }
    }
    cout << ans << endl;
    return 0;
}
