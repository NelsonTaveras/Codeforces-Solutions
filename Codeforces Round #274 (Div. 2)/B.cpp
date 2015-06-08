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

int arr[110];

int main() {
    ios_base::sync_with_stdio(false);
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; ++i)  cin >> arr[i];
    set<PI> up, down;
    for(int i = 0; i < n; ++i){
        up.insert(mp(arr[i], i + 1));
        down.insert(mp(arr[i], i + 1));
    }
    vector<PI> ans;
    for(int i = 0; i < k; ++i){
        PI mi = *down.begin();
        PI ma = *up.rbegin();
        if(ma.first - mi.first <= 1) break;
        ans.push_back(mp(ma.second, mi.second));
        
        down.erase(mi);
        down.erase(ma);
        
        up.erase(mi);
        up.erase(ma);
        
        mi.first++;
        ma.first--;
        
        up.insert(ma);
        up.insert(mi);
        down.insert(ma);
        down.insert(mi);
    }
    PI mi = *down.begin();
    PI ma = *up.rbegin();
    int res = ma.first - mi.first;
    cout << res << ' ' << (int) ans.size() << endl;
    for(int i = 0; i < ans.size(); ++i){
        cout << ans[i].first << ' ' << ans[i].second << endl;
    }
    return 0;
}
