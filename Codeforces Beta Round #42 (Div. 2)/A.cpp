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
    int N;
    cin >> N;

    map<string, int> M;
    string winner;

    int mx = -1;
    for(int i = 0; i < N; ++i)
    {
        string name;
        cin >> name;

        M[name]++;
        if( M[name]  > mx )
        {
            winner = name;
            mx = M[name];
        }
    }

    cout << winner;
    return 0;
}
