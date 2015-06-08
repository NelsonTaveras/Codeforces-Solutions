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
typedef vector<llong> VI;
typedef vector<VI> VVI;
const llong INF = (llong) 2e9;
#define MOD (llong)  1000000007
const llong MAXN = 100010;

int mat[13][13];

int main()
{
    ios_base::sync_with_stdio(false);
    // freopen("input.txt", "r", stdin);
    int tc;
    cin >> tc;
    while(tc--){
        string S;
        cin >> S;
        vector<pair<int, int> > V;
        for(int i = 1; i <= 12; ++i){
            for(int j = 1; j <= 12; ++j){
                if(i * j == 12){
                    int cur = 0;
                    memset(mat, 0, sizeof(mat));
                    for(int r = 0; r < i; ++r)
                        for(int c = 0; c < j; ++c){
                            mat[r][c] = (S[cur] == 'X');
                            cur++;
                        }
                    for(int c = 0; c < j; ++c){
                        int f = 1;
                        for(int r = 0; r < i; ++r){
                            if(mat[r][c] != 1)
                                f = 0;
                        }
                        if(f > 0){
                            V.push_back(mp(i, j));
                            break;
                        }
                    }
                }
            }
        }
        cout << V.size() << ' ';
        for(int i = 0; i < V.size(); ++i){
            if(i) cout << ' ';
            cout << V[i].first << 'x' << V[i].second;
        }
        cout << endl;
    }
    return 0;
}
