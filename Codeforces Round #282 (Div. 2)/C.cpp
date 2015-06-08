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

bool isValid(string S){
    int len = (int) S.size();
    int open = 0, close = 0;
    for(int i = 0; i < len; ++i){
        if(S[i] == '(')
            open++;
        else
            close++;
        if(close > open) return false;
    }
    if(open != close) return false;
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    
    string S;
    cin >> S;
    
    int open = 0, close = 0, uk = 0;
    for(int i = 0; i < S.size(); ++i){
        if(S[i] == '(')
            open++;
        else if(S[i] == ')')
            close++;
        else
            uk++;
    }
    if(open < close + uk){
        cout << -1 << endl;
        return 0;
    }
    if(open == close){
        cout << -1 << endl;
        return 0;
    }
    int dif = open - close;
    string NS;
    VI ans;
    for(int i = 0; i < S.size(); ++i){
        if(S[i] == '(')
            NS += S[i];
        else if(S[i] == ')')
            NS += S[i];
        else{
            if(uk == 1){
                ans.push_back(dif);
                while(dif > 0){
                    NS += ')';
                    dif--;
                }
            }else{
                NS += ')';
                dif--;
                ans.push_back(1);
            }
            uk--;
        }
    }
    if(isValid(NS)){
        for(int i = 0; i < ans.size(); ++i){
            cout << ans[i] << endl;
        }
    }else{
        cout << -1 << endl;
    }
    return 0;
}



