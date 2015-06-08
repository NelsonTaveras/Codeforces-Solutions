#include <cctype>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <string>
#include <vector>
#include <deque>
#include <list>
#include <set>
#include <map>
#include <bitset>
#include <stack>
#include <queue>
#include <algorithm>
#include <functional>
#include <iterator>
#include <numeric>
#include <utility>

using namespace std;

#define mp make_pair
typedef long long llong;
typedef unsigned long long ullong;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef pair<int, int> PII;
typedef pair<int, PII> PIIP;
typedef pair<PII, char> PIC;
typedef pair<int, char> PICD;
const int INF = (int) 2e9;

int mat[101][101];

int main()
{
    int N, K;
    cin >> N >> K;
    for(int i = 0; i < N; ++i)
        for(int j = 0; j < N; ++j)
            mat[i][j] = 1;
    for(int i = 0; i < N; ++i)
        mat[i][i] = (K - N + 1);
    for(int i = 0; i < N; ++i){
        for(int j = 0; j < N; ++j){
            cout << mat[i][j] << ' ';
        }
        cout << endl;
    }
    return 0;
}
