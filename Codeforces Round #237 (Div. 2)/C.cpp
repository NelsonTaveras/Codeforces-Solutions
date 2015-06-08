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
const int maxn = (llong) 1e6 + 10;
const int MOD = 1000000007;

vector<PI> graph[1234567];
VI lvl[1234567];
int main() {
    ios_base::sync_with_stdio(false);
    int n, k;
    cin >> n >> k;
    int ma = 0;
    for (int i = 0; i < n; ++i) {
        int d;
        cin >> d;
        ma = max(ma, d);
        lvl[d].push_back(i);
    }
    if (lvl[0].size() != 1) {
        cout << -1 << endl;
        return 0;
    }
    graph[0].push_back(mp(k, lvl[0][0]));
    vector<PI> ans;
    for(int i = 1; i <= ma; ++i){
        int id = 0;
        for(int j = 0; j < graph[i - 1].size() && id < lvl[i].size(); ++j){
            while(id < lvl[i].size() && graph[i - 1][j].first > 0){
                graph[i - 1][j].first--;
                graph[i].push_back(mp(k - 1, lvl[i][id]));
                ans.push_back(mp(graph[i - 1][j].second, lvl[i][id]));
                id++;
            }
        }
        if(id != lvl[i].size()){
            cout << -1 << endl;
            return 0;
        }
    }
    cout << (int) ans.size() << endl;
    for(int i = 0; i < ans.size(); ++i){
        cout << ans[i].first + 1 << ' ' << ans[i].second + 1 << endl;
    }
    return 0;
}
