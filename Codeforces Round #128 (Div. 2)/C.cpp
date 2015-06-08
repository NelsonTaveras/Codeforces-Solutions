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
#include <cctype>

using namespace std;

#define mp make_pair
typedef long long llong;
typedef pair<llong, llong> PI;
typedef vector<int> VI;
typedef vector<VI> VVI;
int main()
{
    llong N, D, A, B;
    cin >> N >> D >> A >> B;
    vector<PI> V;
    for(int i = 0; i < N; ++i)
    {
        int X, Y;
        cin >> X >> Y;
        V.push_back(mp(1LL * X*A + Y*B, i + 1));
    }
    sort(V.begin(), V.end());
    VI ans;
    llong sum = 0;
    for(int i = 0; i < N; ++i)
    {
        if(sum + V[i].first <= D)
        {
            ans.push_back(V[i].second);
            sum += V[i].first;
        }
    }
    cout << (int) ans.size() << endl;
    for(int i = 0; i < (int) ans.size(); ++i)
        cout << ans[i] << " ";
    return 0;
}
