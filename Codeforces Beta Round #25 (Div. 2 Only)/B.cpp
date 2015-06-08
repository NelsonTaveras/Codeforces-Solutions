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

int main()
{
    int l;
    cin >> l;
    string S;
    cin >> S;
    if(S.size() % 2 == 0)
    {
        for(int i = 0; i < S.size(); i += 2)
        {
            if( i > 1)
                cout << "-";
            cout << S[i] << S[i + 1];
        }
        return 0;
    }
    else
    {
        cout << S[0] << S[1] << S[2];
        for(int i = 3; i < S.size(); i += 2)
        {
            cout << "-";
            cout << S[i] << S[i + 1];
        }
    }
    return 0;
}
