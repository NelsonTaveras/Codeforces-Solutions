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
using namespace std;

#define mp make_pair
typedef long long llong;
typedef unsigned long long ullong;
typedef pair<llong, llong> PII;
typedef pair<llong, PII> PIP;
typedef vector<int> VI;
typedef vector<VI> VVI;
const int INF = (int) 2e9;
#define MOD (llong)  100999
const int MAXN = 5005;

int mat[1005][1005];

int main()
{
    ios_base::sync_with_stdio(false);
    // freopen("input.txt", "r", stdin);
    int N;
    scanf("%d", &N);
    for(int i = 0; i < N; ++i)
        for(int j = 0; j < N; ++j)
            scanf("%d", &mat[i][j]);
    int ans = 0;
    for(int i = 0; i < N; ++i){
        int p = 0;
        for(int j = 0; j < N; ++j)
            p += mat[i][j] * mat[j][i];
        ans += p;
    }
    ans %= 2;
    int Q;
    scanf("%d", &Q);
    while(Q--){
        int t;
         scanf("%d", &t);
         if(t != 3){
            scanf("%d", &t);
            ans = 1 - ans;
         }
         else
            printf("%d", ans);
    }
    return 0;
}
