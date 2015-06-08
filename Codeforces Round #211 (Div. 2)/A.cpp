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

string ANS[] = {
    "O-|-OOOO",
    "O-|O-OOO",
    "O-|OO-OO",
    "O-|OOO-O",
    "O-|OOOO-",
    "-O|-OOOO",
    "-O|O-OOO",
    "-O|OO-OO",
    "-O|OOO-O",
    "-O|OOOO-",
    "--------",
};

int main()
{
    ios_base::sync_with_stdio(false);
    int N;
    cin >> N;
    if(N == 0){
        cout << ANS[0];
        return 0;
    }
    while(N > 0)
    {
        cout << ANS[N%10] << endl;
        N /= 10;
    }
    return 0;
}
