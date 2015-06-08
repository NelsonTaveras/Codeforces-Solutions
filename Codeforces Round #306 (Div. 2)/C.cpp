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

string S;
int len;
int act[120][10][2];
bool memo[120][10][2];
bool cached[120][10][2];
bool dp(int pos, int m, bool f){
    if(pos >= len){
        return (m % 8 == 0) && f;
    }
    if(cached[pos][m][f]) return memo[pos][m][f];
    bool res = dp(pos + 1, m, f);
    if(res){
        act[pos][m][f] = 1;
    }
    bool res2 = dp(pos + 1, (m*10 + (S[pos] - '0')) % 8, 1);
    if(res2){
        act[pos][m][f] = 2;
    }
    cached[pos][m][f] = 1;
    return memo[pos][m][f] = res | res2;
}
string func(int pos, int m, bool f){
    string ans;
    while(1){
        if(pos >= len) break;
        int choice = act[pos][m][f];
        if(choice == 1){
            pos++;
        }else if(choice == 2){
            ans += S[pos];
            m = (m*10 + (S[pos] - '0')) % 8;
            f = 1;
            pos++;
        }else{
            break;
        }
    }
    return ans;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin >> S;
    len = (int) S.size();
    memset(act, 0, sizeof(act));
    memset(cached, 0, sizeof(cached));
    if(dp(0, 0, 0)){
        cout << "YES" << endl;
        string res = func(0, 0, 0);
        for(int i = 0; i < res.size(); ++i){
            if(res[i] != '0'){
                res = res.substr(i);
                break;
            }
        }
        cout << res << endl;
    }else{
        cout << "NO" << endl;
    }
    return 0;
}
