#include <cmath>
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <map>
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
llong INF = (1LL<<62);
const int inf = (1LL<<30);

int used[110];

VI V;
int func(VI v){
    int ans = 0;
    memset(used, 0, sizeof(used));
    while(1){
        if(v.size() == 0) break;
        int added = 0;
        for(int i = 0; i < v.size(); ++i){
            int j = i;
            int cnt = 0;
            set<int> s;
            while(j < v.size() && v[j] == v[i]){
                s.insert(j);
                j++, cnt++;
            }
            if(cnt >= 3){
                added += cnt;
                VI tmp;
                for(int k = 0; k < v.size(); ++k){
                    if(s.count(k) == 0)
                        tmp.push_back(v[k]);
                }
                v = tmp;
                break;
            }
        }
        if(added == 0) break;
        ans += added;
    }
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(false);
    // freopen("input.txt", "r", stdin);
    int n, k, x;
    cin >> n >> k >> x;
    V = VI(n);
    for(int i = 0; i < n; ++i){
        cin >> V[i]; 
    }
    int ma = 0;
    for(int i = 0; i < n; ++i){
        VI tmp;
        for(int j = 0; j < i; ++j) tmp.push_back(V[j]);
        tmp.push_back(x);
        for(int j = i; j < n; ++j) tmp.push_back(V[j]);
        ma = max(ma, func(tmp));
    }    
    if(ma > 0) --ma;
    cout << ma << endl;
    return 0;
}

