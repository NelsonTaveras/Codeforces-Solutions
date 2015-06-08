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

int arr[12345];

VVI mat;
bool cmpmatrix(VVI v){
    int r = v.size();
    // will add r new rows
    while(v.size() < mat.size()){
        int r = v.size();
        --r;
        while(r >= 0){
            v.push_back(v[r]);
            --r;
        }
    }
    if(v.size() != mat.size()) return false;
    return v == mat;
}
int main()
{
    ios_base::sync_with_stdio(false);
    // freopen("input.txt", "r", stdin);
    int n, m;
    cin >> n >> m;
    mat = VVI(n, VI(m));
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < m; ++j)
            cin >> mat[i][j];
    for(int i = 1; i <= n; ++i){
        VVI cur;
        for(int j = 0; j < i; ++j)
            cur.push_back(mat[j]);
        if(cmpmatrix(cur)){
            cout << i << endl;
            return 0;
        }
    }
    return 0;
}