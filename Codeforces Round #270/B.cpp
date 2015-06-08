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

#define mp make_pair7
typedef long long llong;
typedef unsigned long long ullong;
typedef pair<int, int> PI;
typedef pair<PI, int> PII;
typedef vector<int> VI;
typedef vector<VI> VVI;
llong INF = (1LL << 62);
const int inf = (1LL << 30);
const int maxn = (int) 1e5 + 5;
const int MOD = 1000000007;

using namespace std;

bool p[1234567];

int main() 
{
    int n, k;
    cin >> n >> k;
    VI V(n);
    for(int i = 0; i < n; ++i){
        int f;
        cin >> f;
        V[i] = f;
    }
    sort(V.begin(), V.end());
    int ans = 0;
    int cur = 1;
    reverse(V.begin(), V.end());
    for(int i = 0; i < V.size(); ++i){
        for(int j = 0; j < k; ++j){
            if(i + j >= n) break;
            ans += abs(cur - V[i + j]);
            cur = V[i + j];
        }
        ans += cur - 1;
        cur = 1;
        i += (k - 1);
    }
    cout << ans << endl;
    return 0;
}
