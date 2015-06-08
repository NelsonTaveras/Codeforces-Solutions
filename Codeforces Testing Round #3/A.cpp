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

int arr[2000000];

int main()
{
    int N;
    cin >> N;

    llong sum = 0;
    for(int i = 0; i < N; ++i)
        cin >> arr[i], sum += arr[i];
    if( sum % N )
    {
        cout << 0;
        return 0;
    }
    sum /= N;
    int cnt = 0;
    for(int i = 0; i < N; ++i)
        if( sum == arr[i] )
            cnt++;
    cout << cnt << endl;
    for(int i = 0; i < N; ++i)
            if( sum == arr[i] )
                cout << i + 1 << " ";
    return 0;
}
