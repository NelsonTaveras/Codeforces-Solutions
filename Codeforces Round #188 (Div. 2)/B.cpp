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

typedef long long llong;
typedef vector<int> VI;
typedef vector<VI> VII;

int main()
{
    ios_base::sync_with_stdio(false);
    
    string S;
    cin >> S;
            
    vector<int> V1;
    vector<int> V2;
    int cur = 0;
    while(S.find("heavy", cur) != string::npos)
    {
        int pos = S.find("heavy", cur);
        V1.push_back(pos);
        cur = pos + 5;
    }
    
    cur = 0;
    while(S.find("metal", cur) != string::npos)
    {
        int pos = S.find("metal", cur);
        V2.push_back(pos);
        cur = pos + 5;
    }
    
    llong ANS = 0;
    for(int i = 0; i < V1.size(); ++i)
    {
        int pos = lower_bound(V2.begin(), V2.end(), V1[i]) - V2.begin();
        ANS += (V2.size() - pos);
    }
    cout << ANS;
    return 0;
}
