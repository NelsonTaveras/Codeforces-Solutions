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
const int maxn = (int) 1e5 + 5;
const int MOD = 1000000007;

int vis[20];
string a, b, res;
char add()
{
    for(int i = 0; i < a.size(); ++i){
        if(vis[i]) continue;
        vis[i] = 1;
        return a[i];
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> a >> b;
    sort(a.begin(), a.end());
    if(a[a.size() - 1] == '0'){
        if(b.size() == 1 && b[0] == '0')
            cout << "OK" << endl;
        else
            cout << "WRONG_ANSWER" << endl;
        return 0;
    }
    if(a[0] == '0'){
        for(int i = 1; i < a.size(); ++i){
            if(a[i] != '0'){
                vis[i] = 1;
                res += a[i];
                break;
            }
        }
    }
    while(res.size() != a.size()){
        res += add();
    }
    string ans = "OK";
    if(res != b) ans = "WRONG_ANSWER";
    cout << ans << endl;
    return 0;
}

/*

10 5
1 1 1 1 1 2 8 2 9 9

 */
