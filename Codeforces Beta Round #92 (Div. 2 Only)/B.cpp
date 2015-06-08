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

int main()
{
    int N, K;
    cin >> N >> K;
    vector<string> V(N);
    int best = 1e9;
    for(int i = 0; i < N; ++i)
        cin >> V[i];
    VI per;
    for(int i = 0; i < K; ++i)
        per.push_back(i);
    do{
        vector<string> perc;
        for(int i = 0; i < V.size(); ++i)
        {
            string cur;
            for(int j = 0; j < K; ++j)
                cur += V[i][per[j]];
            perc.push_back(cur);
        }
        sort(perc.begin(), perc.end());
        istringstream is(perc.back());
        istringstream os(perc[0]);
        int mx, mi;
        is >> mx;
        os >> mi;
        best = min(best, mx - mi);
    }while(next_permutation(per.begin(), per.end()));
    cout << best;
    return 0;
}
