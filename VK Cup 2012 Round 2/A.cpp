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
#include <ctime>
#include <cctype>
using namespace std;

#define mp make_pair
typedef long long llong;
typedef unsigned long long ullong;
typedef pair<int, int> PII;
typedef pair<int, PII> PIP;
typedef vector<llong> VI;
typedef vector<VI> VVI;
const llong INF = (llong) 1e9;
#define MOD (llong)  1000000007
const llong MAXN = 100010;

string S, T;
int ls, lt;
int memo[5005][5005][2];
int dp(int ids, int idt, int f){
    if(ids >= ls || idt >= lt) return f;
    if(memo[ids][idt][f] != -1) return memo[ids][idt][f];
    long aux = 0;
    if(f){
        if(S[ids] == T[idt]) aux += dp(ids + 1, idt + 1, 1);
        aux += dp(ids, idt + 1, 1);
    }else{
        // No substring
        if(S[ids] == T[idt]) aux += dp(ids + 1, idt + 1, 1);
        aux += dp(ids + 1, idt, 0);
        aux += dp(ids, idt + 1, 0);
        aux -= dp(ids + 1, idt + 1, 0);
    }
    return memo[ids][idt][f] = ((aux % MOD) + MOD) % MOD;
}
int main()
{
    ios_base::sync_with_stdio(false);
    // freopen("input.txt", "r", stdin);
    cin >> S >> T;
    // S = string(5000,'a');
    // T = string(5000,'a');
    ls = S.size();
    lt = T.size();
    // memset(memo, -1, sizeof(memo));

    for(int ids = ls; ids >= 0; ids--)
        for(int idt = lt; idt >= 0; idt--)
            for(int f = 1; f >= 0; --f){
                if(ids >= ls || idt >= lt) 
                    memo[ids][idt][f] = 0;
                else
                {
                    int aux = 0;
                    if(f){
                        if(S[ids] == T[idt])  aux += (1 + memo[ids + 1][idt + 1][1]);
                        if(aux >= MOD) aux -= MOD;
                        aux += memo[ids][idt + 1][1];
                        if(aux >= MOD) aux -= MOD;
                    }else{
                        // No substring
                        if(S[ids] == T[idt])  aux += (1 + memo[ids + 1][idt + 1][1]);
                        if(aux >= MOD) aux -= MOD;
                        aux += memo[ids + 1][idt][0];
                        if(aux >= MOD) aux -= MOD;
                        aux += memo[ids][idt + 1][0];
                        if(aux >= MOD) aux -= MOD;
                        aux -= memo[ids + 1][idt + 1][0];
                        if(aux >= MOD) aux -= MOD;
                    }
                    memo[ids][idt][f] = ((aux % MOD) + MOD) % MOD;
                }
            }
    // cout << dp(0, 0, 0) % MOD << endl;
    cout << ((memo[0][0][0]%MOD) + MOD)%MOD << endl;
    return 0;
}