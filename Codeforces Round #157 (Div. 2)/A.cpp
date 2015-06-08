#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
#include <cstring>
#include <cstdio>
#include <sstream>
#include <string>
#include <set>

using namespace std;

int main()
{
    bool pos = true;
    for(int i = 0; i < 8; ++i)
    {
        string line;
        cin >> line;

        if( line.find("WW") != string::npos ||
            line.find("BB") != string::npos )
            pos = false;
    }

    cout << ( pos ? "YES" : "NO" );

    return 0;
}
