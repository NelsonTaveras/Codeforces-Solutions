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
llong freq[500];
int main()
{
    string S;
    cin >> S;
    for(int i = 0; i < S.size(); ++i)
        freq[S[i] - '0']++;
    llong ret = 0;
    for(int i = 0; i < 200; ++i)
        ret += (1LL *(freq[i] * (freq[i] + 1) / 2) );
    cout << ret * 2 - (llong) S.size();
    return 0;
}
