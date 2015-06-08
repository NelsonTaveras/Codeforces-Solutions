#include <iostream>
#include <cmath>
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
const int inf = (1LL<<30);

string s;
int n;
int z[100010];
int t[100010];
int v[100010];
void ins(int x,int v)
{
    ++x;
    while(x > 0)
    {
        t[x] += v;
        x -= x & -x;
    }
}
int get(int x)
{
    ++x;
    int ret = 0;
    while(x < 100010)
    {
        ret += t[x];
        x += x & -x;
    }
    return ret;
}
int main(){
    // freopen("input.txt", "r", stdin);
    int L = 0, R = 0;
    cin >> s;
    n = (int) s.size();
    for (int i = 1; i < n; i++) {
      if (i > R) {
        L = R = i;
        while (R < n && s[R-L] == s[R]) R++;
        z[i] = R-L; R--;
      } else {
        int k = i-L;
        if (z[k] < R-i+1) z[i] = z[k];
        else {
          L = i;
          while (R < n && s[R-L] == s[R]) R++;
          z[i] = R-L; R--;
        }
      }
    }
    z[0] = n;
    for(int i = 0; i < n; ++i){
        ins(z[i], 1);
    }
    int ans = 0;
    for(int i = 0; i < n; ++i){
        if(z[i] == n - i){
            // cout << " Numeros mayores que " << n - i << ' ' << get(n - i) << endl;
            v[n - i] = get(n - i);
            if(v[n - i]) ++ans;
            // v[n - i] = 1;
        }
    }
    // v[n] = 1;
    cout << ans << endl;
    for(int i = 0; i <= n; ++i){
        if(v[i] > 0)
            cout << i << ' ' << v[i] << endl;
    }
    return 0;
}
