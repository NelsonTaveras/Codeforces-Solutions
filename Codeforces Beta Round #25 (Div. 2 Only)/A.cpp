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

    int cnt_e = 0, cnt_0 = 0, o = 1000000, e = 1000000;

    for(int i = 0; i < N; ++i)
    {
        int val;
        cin >> val;

        cnt_e += ( val % 2 == 0  );
        cnt_0 += ( val % 2 );

        if( val % 2 )
            o = min(o, i + 1);
        else
            e = min(e, i + 1);
    }

    if( cnt_e == 1 )
        cout << e;
    else
        cout << o;

    return 0;
}
