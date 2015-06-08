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
    vector<PI> V;
    int n;
    cin >> n;
    for(int i = 0; i < n; ++i){
        cin >> x[i] >> k[i];
    }
    int f = 1;
    for(int i = 0; i < n; ++i){
        if(x[i] != 0){
            if(saw.count(mp(x[i] - 1, k[i])) == 0) f = 0;
        }
        saw[mp(x[i], k[i])]++;
    }
    cout << (f ? "YES" : "NO") << endl;
    return 0;
}

