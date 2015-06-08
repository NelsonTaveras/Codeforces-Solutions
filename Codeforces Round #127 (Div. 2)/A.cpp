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
typedef long long llong;
typedef vector<int> VI;
typedef vector<VI> VII;
typedef pair<int, int> PI;
typedef pair<int, PI> PII;

string S;
vector<string> V1, V2;
void gen(string x, int cur)
{
    V1.push_back(x);
    if( cur >= S.size() )
        return ;
    gen(x + S[cur], cur + 1);
    gen(x, cur + 1);
}

bool pal(string s)
{
    string rev = s;
    reverse(s.begin(), s.end());
    return rev == s;
}

int main()
{
    cin >> S;
    gen("", 0);
    for(int i = 0; i < V1.size(); ++i)
        if(pal(V1[i]))
            V2.push_back(V1[i]);
    sort(V2.begin(), V2.end());
    cout << V2.back();
    return 0;
}
