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
    int N, K;
    cin >> N >> K;

    vector<int> arr;
    for(int i = 0; i < N; ++i)
    {
        int id;
        cin >> id;
        arr.push_back(id);
    }
    set<int> S;
    for(int i = K - 1; i < N; ++i)
        S.insert(arr[i]);
    if( (int) S.size() > 1 )
    {
        cout << -1;
        return 0;
    }
    for(int i = K - 2; i >= 0; --i)
    {
        if( arr[i] != arr[i+1] )
        {
            cout << i + 1;
            return 0;
        }
    }
    cout << 0;
    return 0;
}
