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
typedef vector<int> VI;
typedef vector<VI> VII;

int main()
{
    /*
    int A, B;
    cin >> A >> B;
    string S;
    cin >> S;
    int L = count(S.begin(), S.end(), 'L');
    int R = count(S.begin(), S.end(), 'R');
    int U = count(S.begin(), S.end(), 'U');
    int D = count(S.begin(), S.end(), 'D');
    */

  llong R, G, B;
  cin >> R >> G >> B;
  VI ret;
  ret.push_back(R);
  ret.push_back(G);
  ret.push_back(B);
  int mx = -1;
  for(int i = 0; i < (1<<3); ++i)
  {
      int ans = 0;
      vector<int> retc = ret;
      for(int j = 0; j < 3; ++j)
          if( (i&(1<<j)) )
          {
              ans += (retc[j] / 3);
              retc[j] %= 3;
          }
      int mi = min(retc[0], min(retc[1], retc[2]));
      ans += mi;
      retc[0] -= mi, retc[1] -= mi, retc[2] -= mi;
      ans += (retc[0]/3 + retc[1]/3 + retc[2]/3);
      mx = max(mx, ans);
  }
    cout << mx;
    return 0;
}



