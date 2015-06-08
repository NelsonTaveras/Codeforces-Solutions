#include <iostream>
#include <queue>
#include <algorithm>
#include <string>
#include <cmath>
#include <vector>
#include <map>
#include <queue>
#include <string>
#include <cctype>
#include <sstream>
#include <cassert>
#include <cstdio>
#include <cstring>
#include <stack>

using namespace std;

typedef long long llong;
typedef vector<int> VI;
typedef vector<VI> VVI;
int pos[(int) 1e6 + 5];
int main()
{
    int N, K;
    cin >> N >> K;
    if(N < K*3)
    {
        cout << -1;
        return 0;
    }
    int cur = 0;
    for(int i = 0; i < K - 1; ++i)
        for(int j = 0; j < 3; ++j)
            pos[++cur] = i;
    for(int i = 0; i < (N-((K-1)*3)); ++i)
        pos[++cur] = K - 1;;
    if(K & 1)
    {
        for(int i = 0; i < K - 1; i += 2)
            swap(pos[ (i*3) + 2], pos[ ((i+1)*3) + 1] );
        swap(pos[1], pos[N]);
    }
    else
        for(int i = 0; i < K; i += 2)
            swap(pos[ (i*3) + 2], pos[ ((i+1)*3) + 1 ] );
    for(int i = 1; i <= N; ++i)
        cout << pos[i] + 1 << ' ';
    return 0;
}
