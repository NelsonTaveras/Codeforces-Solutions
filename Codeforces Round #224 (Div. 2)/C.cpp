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
#define in cin
#define out cout
const int MAXN = 5005;

llong arr[(int) 1e6];
map<llong, llong> F;
bool f(int i, int j) { return i == j; }
int main()
{
    // freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    int N;
    cin >> N;
    if(N == 1){
      cout << -1;
      return 0;
    }
    for (int i = 0; i < N; ++i)
    {
      cin >> arr[i];
    }
    sort(arr, arr+N);
    set<llong> S;
    llong mi = (1LL<<60);
    llong ma = -mi;
    for (int i = 0; i < N - 1; ++i)
    {
      S.insert(arr[i + 1] - arr[i]);
      mi = min(mi, arr[i + 1] - arr[i]);
      ma = max(ma, arr[i + 1] - arr[i]);
      F[arr[i + 1] - arr[i]]++;
    }
    int aux = 0;
    vector<llong> ans;
    if(S.size() == 1)
    {
      ans.push_back(arr[0] - mi);
      ans.push_back(arr[N - 1] + mi);
      if(N == 2 && (arr[1] - arr[0]) % 2 == 0){
        ans.push_back(arr[0] + (arr[1] - arr[0]) / 2);
      }
    }
    else if(S.size() == 2)
    {
      aux = 0;
      // fix for mi
      vector<llong> vtmp, used;
      for(int i = 0; i < N; ++i) vtmp.push_back(arr[i]);
      int f = 0;
      for(int i = 0; i < N - 1 && f <= 1; ++i){
        if(vtmp[i + 1] - vtmp[i] != mi){
          vtmp[i] += mi;
          used.push_back(vtmp[i]);
          --i;
          f++;
        }
      }
      if(f <= 1){
        ans.push_back(used[0]);
        aux++;
      }
      used.clear();
      vtmp.clear();
      for(int i = 0; i < N; ++i) vtmp.push_back(arr[i]);
      f = 0;
      for(int i = 0; i < N - 1 && f <= 1; ++i){
        if(vtmp[i + 1] - vtmp[i] != ma){
          vtmp[i] += ma;
           used.push_back(vtmp[i]);
          --i;
          f++;
        }
      }
      if(f <= 1){
        ans.push_back(used[0]);
        aux++;
      }
    }
    set<int> ss (ans.begin(), ans.end());
    ans.assign(ss.begin(), ss.end());
    cout << ans.size() << endl;
    for(int i = 0; i < ans.size(); ++i)
      cout << ans[i] << ' ';
    return 0;
}