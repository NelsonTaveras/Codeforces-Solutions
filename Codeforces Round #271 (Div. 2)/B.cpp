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
typedef pair<llong, llong> PI;
typedef pair<PI, llong> PII;
typedef vector<llong> VI;
typedef vector<VI> VVI;
llong INF = (1LL << 62);
const llong inf = (1LL << 30);
const llong maxn = (llong) 1e5 + 5;
const llong MOD = 1000000007;

using namespace std;

map<llong, llong> ans;

int main()
{
    llong n;
    cin >> n;
    VI V(n);
    for(llong i = 0; i < n; ++i) cin >> V[i];
    llong q;
    cin >> q;
    VI Q;
    for(llong i = 0; i < q; ++i){
        llong x;
        cin >> x;
        Q.push_back(x);
    }
    VI tmp = Q;
    sort(Q.begin(), Q.end());
    vector<PI> intervals;
    intervals.push_back(PI(1, V[0]));
    for(llong i = 1; i < n; ++i){
        PI p = intervals[i - 1];
        intervals.push_back(PI(p.second + 1, p.second + V[i]));
    }
    llong curq = 0;
    for(llong i = 0; i < intervals.size(); ++i){
        if(curq >= q) break;
        while(curq < q){
            llong w = Q[curq];
            if(intervals[i].first <= w && w <= intervals[i].second){
                ans[w] = i + 1;
                curq++;
            }else{
                break;
            }
        }
    }
    for(llong i = 0; i < tmp.size(); ++i){
        cout << ans[tmp[i]] << endl;
    }
    return 0;
}

