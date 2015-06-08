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

int arr[10000];

int main()
{
    int N, K;
    cin >> N >> K;

    for(int i = 0; i < K; ++i)
        cin >> arr[i];
    set<int> segments;
    for(int i = 1; i <= N * K; ++i)
        segments.insert(i);
    vector<vector<int> > V(K);
    for(int i = 0; i < K; ++i)
    {
        V[i].push_back(arr[i]);
        segments.erase(arr[i]);
    }

    while(segments.size() > 0)
    {
        for(int i = 0; i < K; ++i)
        {
            V[i].push_back(*segments.begin());
            segments.erase(*segments.begin());
        }
    }

    for(int i = 0; i < K; ++i)
    {
        for(int j = 0; j < V[i].size(); ++j)
            cout << V[i][j] << " ";
        cout << endl;
    }

    return 0;
}
