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
typedef pair<int, int> PI;
typedef long long llong;
typedef vector<int> VI;
typedef vector<VI> VVI;
int INF = 1e9;

int main()
{
    int N;
    cin >> N;
    VI V(N);
    for(int i = 0; i < N; ++i)
        cin >> V[i];
    int ret = 0;
    for(int i = 0; i < N; ++i)
    {
        int cnt = 1;
        int curH = V[i];
        for(int j = i - 1; j >= 0 && V[j] <= curH; --j)
            cnt++, curH = V[j];
        curH = V[i];
        for(int j = i + 1; j < N && V[j] <= curH; ++j)
            cnt++, curH = V[j];
        ret = max(ret, cnt);
    }
    cout << ret;
    return 0;
}
