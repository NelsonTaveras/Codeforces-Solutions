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
#include <ctime>
#include <cctype>
#include <bitset>
using namespace std;

#define mp make_pair
typedef long long llong;
typedef unsigned long long ullong;
typedef pair<llong, llong> PII;
typedef pair<llong, PII> PIP;
typedef vector<llong> VI;
typedef vector<VI> VVI;
const int INF = (llong) 1e9 + 50;
#define MOD (llong)  1000000007
const llong MAXN = 100050;

int arr[150];
int mat[150][150];

int main()
{
    // freopen("input.txt", "r", stdin);
    int N;
    cin >> N;
    int be = INF;
    for(int i = 0; i < N; ++i) cin >> arr[i];
    for(int i = 0; i < N; ++i){
        int k = arr[i];
        int tot = 0;
        for(int j = 0; j < k; ++j){
            int t;
            cin >> t;
            tot += 5*t;
            tot += 15;
        }
        be = min(be, tot);
    }
    cout << be << endl;
    return 0;
}
