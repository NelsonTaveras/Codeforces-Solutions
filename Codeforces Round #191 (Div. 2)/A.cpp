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

#define mp make_pair
typedef long long llong;
typedef unsigned long long ullong;
typedef pair<int, int> PI;
typedef pair<int, PI> PII;
typedef vector<int> VI;
typedef vector<VI> VVI;

int main()
{
    ios_base::sync_with_stdio(false);
    int N;
    cin >> N;
    int mx = 0;
    VI V(N);
    for(int i = 0; i < N; ++i)
        cin >> V[i];
    for(int i = 0; i < N; ++i)
    {
        for(int j = 0; j < N; ++j)
        {
            if( i > j )
                continue;
            VI r = V;
            for(int k = i; k <= j; ++k)
                r[k] = 1 - r[k];
            mx = max(mx, (int) count(r.begin(), r.end(), 1));
        }
    }
    cout << mx;
    return 0;
}
