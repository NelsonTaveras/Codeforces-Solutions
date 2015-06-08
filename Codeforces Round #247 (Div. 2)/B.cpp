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
const int inf = (1LL<<30);

llong a[10][10];

int main()
{
    ios_base::sync_with_stdio(false);
    // freopen("input.txt", "r", stdin);
    for(int i = 0; i < 5; ++i)
        for(int j = 0; j < 5; ++j){
            cin >> a[i][j];
        }
    VI V;
    for(int i = 0; i < 5; ++i) V.push_back(i);
    llong ma = 0;
    do{
        VI tmp = V;
        reverse(tmp.begin(), tmp.end());
        llong res = 0;
        while(tmp.size() > 1){
            int sz = tmp.size();
            for(int i = sz - 1; i > 0; i -= 2){
                // cout << " Talk - > " << tmp[i] + 1 << ' ' << tmp[i - 1] + 1 << endl;
                res += a[tmp[i]][tmp[i - 1]] + a[tmp[i - 1]][tmp[i]];
            }
            tmp.pop_back();
        }
        ma = max(ma, res);
    }while(next_permutation(V.begin(), V.end()));
    cout << ma << endl;
    return 0;
}

