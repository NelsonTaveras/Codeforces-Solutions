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
llong INF = 4e18;

int x[(int) 1e5 + 100];
int k[(int) 1e5 + 100];
map<PI, int> saw;
int main()
{
    ios_base::sync_with_stdio(false);
    // freopen("input.txt", "r", stdin);
    llong mainr, addr, n, m, k;
    cin >> mainr >> addr >> n >> m >> k;
    llong left = n * m - k;
    llong mi = INF;
    for(int i = 0; i <= 10000; ++i){
        for(int j = 0; j <= 10000; ++j){
            llong needmain = mainr * i;
            llong needadd = addr * j;
            if(i*n + j >= left) mi = min(mi, needmain + needadd);
        }
    }
    cout << mi << endl;
    return 0;
}

