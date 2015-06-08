#include <iostream>
#include <ctime>
#include <cstdio>
#include <algorithm>
#include <set>
#include <cstring>
#include <cmath>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    int N;
    cin >> N;
    for(int i = 0; i < N; ++i)
    {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        int mia = min(a, b);
        int mib = min(c, d);
        if(mia + mib <= N){
            cout << i + 1 << ' ' << mia << ' ' << N-mia << endl;
            return 0;
        }
    }
    cout << -1;
    return 0;
}









