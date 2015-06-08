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
typedef vector<int> VI;
typedef vector<VI> VII;

int main()
{
    string S;
    cin >> S;
    int ret = -1;
    int cnt4 = count(S.begin(), S.end(), '4');
    int cnt7 = count(S.begin(), S.end(), '7');
    if(cnt4 || cnt7)
    {
        if(cnt4)
            ret = 4;
        if(cnt7 > cnt4)
            ret = 7;
    }
    cout << ret;
    return 0;
}
