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

int saw[(int) 1e7 + 20];
int ans[(int) 1e7 + 20];
int p[(int) 1e7 + 20];
int main()
{
    // freopen("input.txt", "r", stdin);
    int N;
    scanf("%d", &N);
    for(int i = 0; i < N; ++i){
      int v;
      scanf("%d", &v);
      saw[v]++;
    }
    p[0] = p[1] = 1;
    for(llong i = 2; i <= 10000000; ++i){
      for(llong j = i * i; j <= 10000000; j += i)
        p[j] = 1;
    }
    int cursz = 0;
    for(int i = 2; i <= 10000000; ++i)
      if(p[i] == 0){
        p[cursz++] = i;
      }
    for(int i = 0; i < cursz; ++i){
      int pp = p[i];
      ans[pp] += saw[pp];
      for(int j = 2*pp; j <= 10000000; j += pp){
        ans[pp] += saw[j];
      }
    }
    int sum = 0;
    int cur = 0;
    saw[0] = saw[1] = 0;
    for(int i = 1; i <= 10000000; ++i){
      if(p[cur] == i){
        sum += ans[i];
        cur++;
      }
      saw[i] = sum;
    }
    scanf("%d", &N);
    for(int i = 0; i < N; ++i){
      int l, r;
      scanf("%d %d", &l, &r);
      if(l >= 10000000) 
        printf("0\n");
      else{
        printf("%d\n", saw[min(r, 10000000)] - saw[l - 1]);
      }
    }
    return 0;
}