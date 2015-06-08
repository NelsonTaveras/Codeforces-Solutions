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

using namespace std;

#define mp make_pair
typedef long long llong;
typedef unsigned long long ullong;
typedef pair<int, int> PII;
typedef pair<int, PII> PIP;
typedef vector<int> VI;
typedef vector<VI> VVI;
const int INF = (int) 2e9;
#define MOD (llong)  100999

int mat[150][150];
int has[150][150];
void func(int a, int b)
{
    int gota = 0, gotb = 0;
    for(int i = 0; i <= 100; ++i)
        if(has[a][i] != has[b][i]){
            if(has[a][i] == 0 && has[b][i] > 0) gotb++;
            else if(has[b][i] == 0 && has[a][i]) gota++;
            else gota++, gotb++;
        }
    if(!gota && gotb) mat[a][b] = 1;
    if(gota && !gotb) mat[b][a] = 1;
    if(!gota && !gotb) mat[a][b] = mat[b][a] = 1;
}

int main()
{
    // freopen("input.txt", "r", stdin);
    int N;
    cin >> N;
    for(int i = 0; i < N; ++i){
        int k;
        cin >> k;
        for(int j = 0; j < k; ++j){
            int v;
            cin >> v;
            has[i][v] = 1;
        }
    }
    for(int i = 0; i < N; ++i)
        for(int j = 0; j < N; ++j)
            if(i != j) func(i, j);
    for(int i = 0; i < N; ++i){
        // can i win?
        int f = 1;
        for(int j = 0; j < N && f; ++j)
            if(i != j && mat[j][i]) f = 0;
        cout << (f ? "YES" : "NO") << endl;
    }
    return 0;
}
