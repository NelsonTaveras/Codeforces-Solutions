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
#include <ctime>

using namespace std;

#define mp make_pair
typedef long long llong;
typedef unsigned long long ullong;
typedef pair<int, int> PII;
typedef pair<int, PII> PIP;
typedef vector<int> VI;
typedef vector<VI> VVI;
const int INF = (int) 1e9;
int mat[100][100];
int sumrow[100];
int sumcol[100];
int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int N, M, A, B, C;
    cin >> N >> M;
    for(int i = 0; i < N; ++i)
        for(int j = 0; j < M; ++j)
            cin >> mat[i][j];
    for(int i = 0; i < N; ++i)
        for(int j = 0; j < M; ++j)
            sumrow[i] += mat[i][j];
    for(int j = 0; j < M; ++j)
        for(int i = 0; i < N; ++i)
            sumcol[j] += mat[i][j];
    cin >> A >> B >> C;
    int ways = 0;
    for(int i = 0; i < N - 2; ++i){
        for(int j = i + 1; j < N - 1; ++j){
            int sumA = 0, sumB = 0, sumC = 0;
            for(int l = 0; l <= i; ++l)
                sumA += sumrow[l];
            for(int l = i + 1; l <= j; ++l)
                sumB += sumrow[l];
            for(int l = j + 1; l < N; ++l)
                sumC += sumrow[l]; 
            map<int, int> check;
            check[A]++;
            check[B]++;
            check[C]++;
            if(check[sumA])
                check[sumA]--;
            if(check[sumB])
                check[sumB]--;
            if(check[sumC])
                check[sumC]--;
            if(!check[A] && !check[B] && !check[C])
                ways++;
        }
    }
    for(int i = 0; i < M - 2; ++i){
        for(int j = i + 1; j < M - 1; ++j){
            int sumA = 0, sumB = 0, sumC = 0;
            for(int l = 0; l <= i; ++l)
                sumA += sumcol[l];
            for(int l = i + 1; l <= j; ++l)
                sumB += sumcol[l];
            for(int l = j + 1; l < M; ++l)
                sumC += sumcol[l];
            map<int, int> check;
            check[A]++;
            check[B]++;
            check[C]++;
            if(check[sumA])
                check[sumA]--;
            if(check[sumB])
                check[sumB]--;
            if(check[sumC])
                check[sumC]--;
            if(!check[A] && !check[B] && !check[C])
                ways++;
        }
    }
    cout << ways << endl;
}   
