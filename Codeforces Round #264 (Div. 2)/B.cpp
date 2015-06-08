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
    int n;
    cin >> n;
    int last = 0;
    int ans = 0;
    int cure = 0;
    for(int i = 0; i < n; ++i){
        int x;
        cin >> x;
        int earn = last - x;
        cure += earn;
        if(cure < 0){
            ans += cure*-1;
            cure = 0;
        }
        last = x;
    }
    cout << ans << endl;
    return 0;
}
