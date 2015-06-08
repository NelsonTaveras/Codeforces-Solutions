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
typedef pair<int, int> PII;
typedef pair<int, PII> PIP;
typedef vector<int> VI;
typedef vector<VI> VVI;

llong INF = (1LL << 62);
const int inf = (1LL << 30);
const int maxn = (llong) 1e6 + 10;
const int MOD = 1000000007;

int main(){
    
    ios_base::sync_with_stdio(false);
    
    int n, m;
    cin >> n >> m;
    vector<string> V;
    for(int i = 0; i < n; ++i){
        string S;
        cin >> S;
        V.push_back(S);
    }
    int ans = 0;
    for(int r1 = 0; r1 < n - 1; ++r1){
        for(int c1 = 0; c1 < m - 1; ++c1){
            int r2 = r1 + 1;
            int c2 = c1 + 1;
            int rows = r2 - r1 + 1;
            int cols = c2 - c1 + 1;
            if(rows * cols == 4){
                bool f = false, a = false, c = false, e = false;
                for(int k = r1; k <= r2; ++k){
                    for(int kk = c1; kk <= c2; ++kk){
                        if(V[k][kk] == 'f') f = true;
                        if(V[k][kk] == 'a') a = true;
                        if(V[k][kk] == 'c') c = true;
                        if(V[k][kk] == 'e') e = true;
                    }
                }
                if(f && a && c && e){
                    //cout << r1 << ' ' << r2 << ' ' << c1 << ' ' << c2 << endl;
                    ans++;
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}
