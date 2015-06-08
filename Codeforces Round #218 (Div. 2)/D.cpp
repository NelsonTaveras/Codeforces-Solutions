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

int cap[3 * (int) 1e5];
int cur[3 * (int) 1e5];
int main()
{
    // ios_base::sync_with_stdio(false);
    int N;
    cin >> N;
    set<int> S;
    for(int i = 0; i < N; ++i){
      cin >> cap[i];
      S.insert(i);
    }
    int Q;
    cin >> Q;
    for(int i = 0; i < Q; ++i){
      int t, k;
      cin >> t >> k;
      --k;
      if(t == 1){
        int x;
        cin >> x;
          while(x > 0){
            if(cur[k] + x < cap[k]){
              cur[k] += x;
              x = 0;
            }
            else if(cur[k] + x == cap[k]){
              cur[k] += x;
              x = 0;
              S.erase(k);
            }else{
              int mcap = cap[k] - cur[k];
              cur[k] = cap[k];
              x -= mcap;
              if(S.upper_bound(k) == S.end()) break;
              int nxt = *S.upper_bound(k);
              S.erase(k);
              k = nxt;
            }
          }
      }else{
        cout << cur[k] << endl;
      }
    }
    return 0;
}