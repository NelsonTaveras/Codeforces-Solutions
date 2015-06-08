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
    vector<string> V;
    for(int i = 0; i < 4; ++i)
    {
        string s;
        cin >> s;

        V.push_back(s);
    }

    bool pos = false;
    for(int r = 0; r < 3; ++r)
    {
        for(int c = 0; c < 3; ++c)
        {
            int dots = 0, nums = 0;
            dots += ( V[r][c] == '.' );
            nums += ( V[r][c] != '.' );
            dots += ( V[r][c+1] == '.' );
            nums += ( V[r][c+1] != '.' );
            dots += ( V[r+1][c] == '.' );
            nums += ( V[r+1][c] != '.' );
            dots += ( V[r+1][c+1] == '.' );
            nums += ( V[r+1][c+1] != '.' );

            if( dots >= 3 || nums >= 3 )
                pos = true;
        }
    }

    cout << ( pos ? "YES" : "NO" );

    return 0;
}
