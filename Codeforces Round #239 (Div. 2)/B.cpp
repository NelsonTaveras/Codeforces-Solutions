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

int fa[55];
int fb[55];

int main()
{
    // freopen("input.txt", "r", stdin);
    string A, B;
    cin >> A >> B;
    int ma = 0;
    for(int i = 0; i < A.size(); ++i)
        fa[A[i] - 'a']++;
    for(int i = 0; i < B.size(); ++i)
        fb[B[i] - 'a']++;
    for(int i = 0; i <= 26; ++i){
        if(fb[i] > 0 && fa[i] == 0){
            cout << -1 << endl;
            return 0;
        }
    }
    for(int i = 0; i <= 26; ++i){
        if(fb[i] > 0){
            int want = fb[i];
            int got = fa[i];
            if(got >= want){
                ma += want;
                fa[i] -= want;
            }else{
                ma += got;
                fa[i] = 0;
            }
        }
    }
    cout << ma << endl;
    return 0;
}