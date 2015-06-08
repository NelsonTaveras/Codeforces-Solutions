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

int main()
{
    string S;
    cin >> S;
    vector<string> ans;
    for(int i = 0; i < S.size(); ++i)
    {
        string sub = "";
        while(S[i] != '@' && i < S.size())
            sub += S[i], i++;
        if(sub.size() == 0)
        {
            cout << "No solution";
            return 0;
        }
        sub += '@';
        i++;
        if(i >= S.size())
        {
            cout << "No solution";
            return 0;
        }
        if(S.find('@', i) == string::npos)
        {
            sub += S.substr(i);
            ans.push_back(sub);
            break;
        }
        string after;
        if(i < S.size() && S[i] == '@')
        {
            cout << "No solution";
            return 0;
        }
        else
        {
            if(i<S.size())
                sub += S[i];
            ans.push_back(sub);
        }
    }
    for(int i = 0; i < ans.size(); ++i)
    {
        if(i)
            cout << ',';
        cout << ans[i];
    }
    return 0;
}
