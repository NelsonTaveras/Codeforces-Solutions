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
typedef unsigned long long llong;
typedef pair<llong, llong> PI;
typedef pair<PI, llong> PII;
typedef vector<llong> VI;
typedef vector<VI> VVI;
llong INF = (1LL << 62);
const llong inf = (1LL << 30);
const llong maxn = (llong) 1e5 + 5;
const llong MOD = 1000000007;

using namespace std;

int a[1234567];
int b[1234567];
int f[12345678];
VI needle, hay;
void ff(){
    int j = -1, i = 0;
    f[0] = -1;
    while(i < (int) needle.size()){
        while(j >= 0 && needle[i] != needle[j]) j = f[j];
        f[++i] = ++j;
    }
}
int search(){
    int j = 0, i = 0, res = 0;
    while(i < (int) hay.size()){
        while(j >= 0 && hay[i] != needle[j]) j = f[j];
        i++, j++;
        if(j == needle.size()){
            ++res;
            j = f[j];
        }
    }
    return res;
}
int main() {
    ios_base::sync_with_stdio(false);
    int n, w;
    cin >> n >> w;
    string S, T;
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    for (int i = 0; i < w; ++i)
        cin >> b[i];
    if(w == 1){
        cout << n << endl;
        return 0;
    }
    if(w > n){
        cout << 0 << endl;
        return 0;
    }
    for (int i = 1; i < n; ++i) {
        hay.push_back(a[i] - a[i - 1]);
    }
    for (int i = 1; i < w; ++i) {
        needle.push_back(b[i] - b[i - 1]);
    }
//  cout << S << ' ' << T << endl;
    ff();
    cout << search() << endl;
    return 0;
}
