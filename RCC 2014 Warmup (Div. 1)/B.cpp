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

struct ff{
    llong price, mask, monitors;
};

bool cmp(const ff &A, const ff &B){
    return A.monitors < B.monitors;
}

ff f[150];
llong memo[1<<21];

int main()
{
    // ios_base::sync_with_stdio(false);
    // freopen("input.txt", "r", stdin);
    llong n, m, b;
    cin >> n >> m >> b;
    for(int i = 0; i < n; ++i){
        int k;
        cin >> f[i].price >> f[i].monitors >> k;
        for(int j = 0; j < k; ++j){
            int id;
            cin >> id;
            --id;
            f[i].mask |= (1<<id);
        }
    }
    sort(f, f + n, cmp);
    for(int i = 0; i < (1<<m); ++i) memo[i] = INF;
    memo[0] = 0;
    llong mi = INF;
    for(int i = 0; i < n; ++i){
        for(int mask = 0; mask < (1<<m); ++mask)
            memo[mask | f[i].mask] = min(memo[mask | f[i].mask], memo[mask] + f[i].price);
        llong res = memo[ (1<<m) - 1];
        if(res != INF) mi = min(mi, res + f[i].monitors * b);
    }
    if(mi == INF) mi = -1;
    cout << mi << endl;
    return 0;
}