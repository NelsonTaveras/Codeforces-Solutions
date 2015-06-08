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

int saw[1005];

int main()
{
    ios_base::sync_with_stdio(false);
    // freopen("input.txt", "r", stdin);
    int n, m, mi, ma;
    cin >> n >> m >> mi >> ma;
    VI V;
    int sawmi = 0;
    int sawma = 0;
    for(int i = 0; i < m; ++i){
        int x;
        cin >> x;
        if(x < mi || x > ma){
            cout << "Incorrect" << endl;
            return 0;
        }
        if(x == mi) sawmi = 1;
        if(x == ma) sawma = 1;
        saw[x] = 1;
    }
    int left = n - m;
    if(sawmi == 0 && left > 0)
        saw[mi] = 1, left--;
    if(sawma == 0 && left > 0)
        saw[ma] = 1, left--;
    if(saw[mi] == 0 || saw[ma] == 0){
        cout << "Incorrect" << endl;
        return 0;
    }
    cout << "Correct" << endl;
    return 0;
}