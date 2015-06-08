#include <iostream>
#include <cstring>
#include <cmath>
#include <cstdio>
#include <vector>

using namespace std;

typedef vector<int> VI;
typedef vector<VI> VVI;
int X[150];
int Y[150];
double dist(int A, int B)
{
    double D = (((X[A]-X[B]) * (X[A]-X[B])) + ((Y[A]-Y[B]) * (Y[A]-Y[B])));
    return sqrt(D) / 50;
}

int main()
{
    int N, K;
    cin >> N >> K;
    for(int i = 0; i < N; ++i)
        cin >> X[i] >> Y[i];
    double sum = 0;
    for(int i = 0; i < N - 1; ++i)
        sum += dist(i, i + 1);
    printf("%.7lf", sum * K);
    return 0;
}

