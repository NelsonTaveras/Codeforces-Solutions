#include <iostream>
#include <cmath>
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
const int maxn = (int) 1e9 + 5;

int main()
{
    ios_base::sync_with_stdio(false);
    // freopen("input.txt", "r", stdin);
    VI V;
    string s;
    cin >> s;
    int k;
    cin >> k;
    int n = (int) s.size();
    for(int i = 0; i < n; ++i) V.push_back(s[i] - '0');
    while(k > 0){
        int f = 0;
        for(int i = 0; i < n && !f; ++i){
            // biggest one that can be on i
            int cur = V[i];
            for(int j = i + 1; j < n; ++j){
                if(j - i > k) continue;
                if(V[j] > cur)
                    cur = V[j];
            }
            if(cur == V[i]) continue;
            for(int j = i + 1; j < n && !f; ++j){
                if(V[j] == cur){
                    int swaps = j - i;
                    if(swaps <= k){
                        f = 1;
                        k -= swaps;
                        int ii = i, jj = j;
                        while(jj != ii && jj - 1 >= 0){
                            swap(V[jj], V[jj - 1]);
                            --jj;
                        }
                    }
                }
            }
        }
        if(!f) break;
    }
    for(int i = 0; i < n; ++i) cout << V[i];
    return 0;
}