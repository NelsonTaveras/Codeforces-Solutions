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

    int succa = 0, succb = 0;
    int senta = 0, sentb = 0;

    for(int i = 0; i < N; ++i)
    {
        int ti, xi, yi;
        cin >> ti >> xi >> yi;

        if( ti == 1 )
        {
            succa += xi;
            senta += 10;
        }
        else
        {
            succb += xi;
            sentb += 10;
        }
    }

    cout << ( ( succa >= senta/2 ) ? "LIVE" : "DEAD" ) << endl;
    cout << ( ( succb >= sentb/2 ) ? "LIVE" : "DEAD" );

    return 0;
}
