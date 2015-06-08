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
    int N;
    cin >> N;
    VI V(N);
    for(int i = 0; i < N; ++i)
        cin >> V[i];
    sort(V.begin(), V.end());
    int sum = 0;
    int ret = 0;
    int i;
    for(i = 0; i < N; ++i)
    {
        if( sum + V[i] <= 350 )
        {
            sum += V[i];
            ret++;
        }
        else
            break;
    }
    if( i < N)
        V[i] -= (350 - sum);
    sum = 0;
    int penalty = 0;
    for( ; i < N; ++i)
    {
        if( sum + V[i] <= 360 )
        {
            sum += V[i];
            penalty += sum;
            ret++;
        }
    }
    cout << ret << " " << penalty;
    return 0;
}
