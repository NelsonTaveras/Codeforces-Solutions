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

#define mp make_pair7
typedef long long llong;
typedef unsigned long long ullong;
typedef pair<int, int> PI;
typedef pair<PI, int> PII;
typedef vector<int> VI;
typedef vector<VI> VVI;
llong INF = (1LL << 62);
const int inf = (1LL << 30);
const int maxn = (int) 1e5 + 5;
const int MOD = 1000000007;

using namespace std;

string func(vector<string> V1, vector<string> V2){
    int n1 = V1.size();
    int n2 = V2.size();
    // n1 < n2
    string ma = "NONE";
    for(int i = 0; i < n1; ++i){
        for(int j = 0; j < n2; ++j){
            if(V1[i] < V2[j]){
                // this one is valid
                if(ma == "NONE" || V2[j] < ma)
                    ma = V2[j];
            }
        }
    }
    return ma;
}

int main() 
{
    int n;
    cin >> n;
    vector<string> F(n);
    vector<string> S(n);
    for(int i = 0; i < n; ++i){
        string f, s;
        cin >> F[i] >> S[i];
    }
    VI arr(n);
    for(int i = 0; i < n; ++i){
        cin >> arr[i];
        --arr[i];
    }
    if(n == 1){
        cout << "YES" << endl;
        return 0;
    }
    string ans = "YES";
    
    vector<string> v1, v2;
    v1.push_back(F[ arr[0] ]);
    v1.push_back(S[ arr[0] ]);
    v2.push_back(F[ arr[1] ]);
    v2.push_back(S[ arr[1] ]);
    string last = func(v1, v2);
    for(int i = 2; i < n; ++i){
        if(last == "NONE"){
            ans = "NO";
            break;
        }
        vector<string> tmp1, tmp2;
        tmp1.push_back(last);
        tmp2.push_back(F[ arr[i] ]);
        tmp2.push_back(S[ arr[i] ]);
        last = func(tmp1, tmp2);
    }
    if(last == "NONE") ans = "NO";
    cout << ans << endl;
    return 0;
}
