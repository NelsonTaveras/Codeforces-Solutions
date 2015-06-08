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

PII r[1005];
PI t[1005];
int memo[1001][1001];
int act[1001][1001];
int dp(int id, int table, int n, int k){
    if(id >= n || table >= k) return 0;
    if(memo[id][table] != -1) return memo[id][table];
    int ans = 0;
    if(t[table].first >= r[id].first.first){
        int w = r[id].first.second + dp(id + 1, table + 1, n, k);
        if(w > ans){
            act[id][table] = 1;
            ans = w;
        }
    }
    else{
        int w = dp(id, table + 1, n, k);
        if(w > ans){
            act[id][table] = 2;
            ans = w;
        }
    }
    // skip him
    int w = dp(id + 1, table, n, k);
    if(w > ans){
        act[id][table] = 3;
        ans = w;
    }
    return memo[id][table] = ans;
}
vector<PI> solve(int id, int table, int n, int k){
    vector<PI> ans;
    while(id < n && table < k){
        int choice = act[id][table];
        if(choice == 1){
            // seat him
            ans.push_back(mp(r[id].second, t[table].second));
            id++, table++;
        }else if(choice == 2){
            table++;
        }else if(choice == 3){
            id++;
        }else{
            break;
        }
    }
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(false);
    // freopen("input.txt", "r", stdin);
    int n, k;
    cin >> n;
    for(int i = 0; i < n; ++i) 
        cin >> r[i].first.first >> r[i].first.second, r[i].second = i;
    cin >> k;
    for(int i = 0; i < k; ++i)
        cin >> t[i].first, t[i].second = i;
    sort(r, r + n);
    sort(t, t + k);
    memset(memo, -1, sizeof(memo));
    int res = dp(0, 0, n, k);
    vector<PI> ans = solve(0, 0, n, k);
    cout << (int) ans.size() << ' ' << res << endl;
    for(int i = 0; i < ans.size(); ++i)
        cout << ans[i].first + 1 << ' ' << ans[i].second + 1 << endl;
    return 0;
}

