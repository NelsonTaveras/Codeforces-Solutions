#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <sstream>
#include <cmath>
#include <string>
#include <cstring>
#include <cctype>
#include <algorithm>
#include <vector>
#include <bitset>
#include <queue>
#include <stack>
#include <utility>
#include <list>
#include <set>
#include <map>

using namespace std;

typedef vector<int> VI;
typedef vector<VI> VVI;
const int INF = (int) 1e9;

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int N;
    cin >> N;
    VI V(N);
    for(int i = 0; i < N; ++i)
        cin >> V[i];
    sort(V.begin(), V.end());
    int mi = INF;
    for(int i = 0; i < N; ++i)
    {
        int up = upper_bound(V.begin(), V.end(), V[i] * 2) - V.begin();
        mi = min(mi, N - up + i);
    }
    cout << mi;
    return 0;
}
