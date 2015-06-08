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
typedef pair<int, int> PI;
typedef long long llong;
typedef vector<int> VI;
typedef vector<VI> VVI;
int INF = 1e9;
int main()
{
    string line;
    getline(cin, line);
    for(int i = line.size() - 1; i >= 0; i--)
    {
        char c = tolower(line[i]);
        string ans = "NO";
        if( c >= 'a' && c <= 'z' )
        {
            if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'y')
                ans = "YES";
            cout << ans;
            return 0;
        }
    }
    return 0;
}
