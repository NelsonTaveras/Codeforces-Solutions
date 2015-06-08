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

int arr[150];

int main()
{
    ios_base::sync_with_stdio(false);
    vector<string> V(3);
    for(int i = 0; i < 3; ++i) cin >> V[i];
    for(int i = 0; i < 3; ++i){
        for(int j = 0; j < 3; ++j){
            int xi = i;
            int yi = j;
            int xf = 2 - i;
            int yf = 2 - j;
            if(V[xi][yi] != V[xf][yf]){
                cout << "NO" << endl;
                return 0;
            }
        }
    }
    cout << "YES" << endl;
    return 0;
}

/*

10 5
1 1 1 1 1 2 8 2 9 9

 */
