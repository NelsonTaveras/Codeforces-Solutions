#include <cmath>
#include <ctime>
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

typedef unsigned long long ullong;
typedef long long llong;
typedef vector<llong> VI;
typedef vector<VI> VII;

using namespace std;

unsigned long long powmod(unsigned long long x, unsigned int n, unsigned int m) {
   unsigned long long res = 1;
   x %= m;
   while (true) {
      if (n & 1) {
         res = (res * x) % m;
      // n--;
      }
      n >>= 1;
      if (n == 0) break;
      x = (x * x) % m;
   }
   return (unsigned long long) res;
}
map<char, string> M;

int main()
{
    M['>'] = "1000";
    M['<'] = "1001";
    M['+'] = "1010";
    M['-'] = "1011";
    M['.'] = "1100";
    M[','] = "1101";
    M['['] = "1110";
    M[']'] = "1111";
    string S, ret;
    cin >> S;
    for(int i = 0; i < (int) S.size(); ++i)
        ret += M[S[i]];
    llong res = 0;
    int sz = (int) ret.size();
    for(int i = 0; i < sz; ++i)
    {
        if(ret[i] == '1')
            res += powmod(2, sz - i - 1, 1000003);
        res %= 1000003;
    }
    cout << res;
    return 0;
}
