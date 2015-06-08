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

bool b[55];

int main()
{
    ios_base::sync_with_stdio(false);
    // freopen("input.txt", "r", stdin);
    b['A'-'A'] = 1;
    b['H'-'A'] = 1;
    b['I'-'A'] = 1;
    b['M'-'A'] = 1;
    b['O'-'A'] = 1;
    b['T'-'A'] = 1;
    b['U'-'A'] = 1;
    b['V'-'A'] = 1;
    b['W'-'A'] = 1;
    b['X'-'A'] = 1;
    b['Y'-'A'] = 1;
    string S;
    cin >> S;
    for(int i = 0; i < S.size(); ++i){
        if( b[S[i] - 'A'] == 0){
            cout << "NO" << endl;
            return 0;
        }
    }
    string S2 = S;
    reverse(S2.begin(), S2.end());
    string ans = "YES";
    if(S != S2) ans = "NO";
    cout << ans << endl;
    return 0;
}