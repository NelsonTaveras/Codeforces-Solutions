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

int main()
{
    ios_base::sync_with_stdio(false);
    // freopen("input.txt", "r", stdin);
    int N;
    cin >> N;
    for(int i = 0; ; i++){
        int f = 4 * i;
        if(f > N) break;
        if( (N - f) % 7 == 0 ){
            string ans;
            ans += string(i, '4');
            ans += string((N - f) / 7, '7');
            cout << ans << endl;
            return 0;
        }
    }
    cout << -1 << endl;
    return 0;
}