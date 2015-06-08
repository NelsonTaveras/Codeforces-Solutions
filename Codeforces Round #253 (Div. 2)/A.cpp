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
typedef unsigned long long ullong;
typedef pair<int, int> PI;
typedef pair<PI, int> PII;
typedef vector<int> VI;
typedef vector<VI> VVI;
llong INF = (1LL<<62);
const int inf = (1LL<<30);
const int maxn = (int) 1e9 + 5;
const int MOD = 1000000007;

int main()
{
    string S;
    getline(cin, S);
    int sz = S.size();
    set<char> ans;
    for(int i = 0; i < S.size(); ++i){
        if(S[i] >= 'a' && S[i] <= 'z')
            ans.insert(S[i]);
    }
    cout << ans.size() << endl;
    return 0;
}
