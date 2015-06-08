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
const int inf = (1LL << 30);
const int maxn = (llong) 1e5 + 5;
const int MOD = 1000000007;

using namespace std;

int main()
{
    vector<string> V;
    V.push_back("qwertyuiop");
    V.push_back("asdfghjkl;");
    V.push_back("zxcvbnm,./");
    char c;
    cin >> c;
    string S;
    cin >> S;
    string ans;
    for(int i = 0; i < S.size(); ++i){
        char C = S[i];
        int f = 1;
        for(int j = 0; j < V.size() && f; ++j){
            for(int k = 0; k < V[j].size() && f; ++k){
                if(V[j][k] == C){
                    if(c == 'R')
                        ans += V[j][k - 1];
                    else
                        ans += V[j][k + 1];
                }
            }
        }
        
    }
    cout << ans << endl;
    return 0;
}

