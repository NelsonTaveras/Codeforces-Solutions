#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <cstdlib>
#include <map>
#include <ctime>
#include <set>
#include <algorithm>
#include <cstring>
#include <queue>
#include <stack>
#include <sstream>
#include <cstdio>
#include <bitset>

using namespace std;

#define mp make_pair
typedef long long llong;
typedef pair<int, int> PII;
typedef pair<int, PII> PIP;
typedef vector<int> VI;
typedef vector<VI> VVI;

llong INF = (1LL << 62);
const int inf = (1LL << 30);
const int maxn = (llong) 1e6 + 10;
const int MOD = 1000000007;

int arr[50];

int main() {
    ios_base::sync_with_stdio(false);

    // Number X can convert to Y if X & Y == X 

    // Number 0
    arr[0] |= (1 << 1);
    arr[0] |= (1 << 2);
    arr[0] |= (1 << 3);
    arr[0] |= (1 << 4);
    arr[0] |= (1 << 5);
    arr[0] |= (1 << 6);

    // Number 1
    arr[1] |= (1 << 3);
    arr[1] |= (1 << 4);

    // Number 2
    arr[2] |= (1 << 2);
    arr[2] |= (1 << 3);
    arr[2] |= (1 << 5);
    arr[2] |= (1 << 6);
    arr[2] |= (1 << 7);

    arr[3] |= (1 << 2);
    arr[3] |= (1 << 3);
    arr[3] |= (1 << 4);
    arr[3] |= (1 << 5);
    arr[3] |= (1 << 7);

    arr[4] |= (1 << 1);
    arr[4] |= (1 << 3);
    arr[4] |= (1 << 4);
    arr[4] |= (1 << 7);

    arr[5] |= (1 << 1);
    arr[5] |= (1 << 2);
    arr[5] |= (1 << 4);
    arr[5] |= (1 << 5);
    arr[5] |= (1 << 7);

    arr[6] |= (1 << 1);
    arr[6] |= (1 << 2);
    arr[6] |= (1 << 4);
    arr[6] |= (1 << 5);
    arr[6] |= (1 << 6);
    arr[6] |= (1 << 7);

    arr[7] |= (1 << 2);
    arr[7] |= (1 << 3);
    arr[7] |= (1 << 4);

    arr[8] |= (1 << 1);
    arr[8] |= (1 << 2);
    arr[8] |= (1 << 3);
    arr[8] |= (1 << 4);
    arr[8] |= (1 << 5);
    arr[8] |= (1 << 6);
    arr[8] |= (1 << 7);

    arr[9] |= (1 << 1);
    arr[9] |= (1 << 2);
    arr[9] |= (1 << 3);
    arr[9] |= (1 << 4);
    arr[9] |= (1 << 5);
    arr[9] |= (1 << 7);

    string S;
    cin >> S;

    int first = 0, second = 0;
    int d = S[0] - '0';
    for (int x = 0; x <= 9; ++x)
        if ((arr[d] & arr[x]) == arr[d])
            first++;
    d = S[1] - '0';
    for (int x = 0; x <= 9; ++x)
        if ((arr[d] & arr[x]) == arr[d])
            second++;

    cout << first * second << endl;

    return 0;
}
