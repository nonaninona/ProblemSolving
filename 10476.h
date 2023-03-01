#pragma once
#include <iostream>
#include <algorithm>
#define tmax(a, b, c) max(a, max(b,c))
using namespace std;
int N, K;
int v[200][2];
int dp[200][200][3];
int temp;
int main_10476()
{
    cin >> N;
    cin >> K;
    for (int i = 0; i < N; i++) {
        cin >> v[i][0];
        cin >> v[i][1];
    }
    cin >> temp;
    cin >> temp;

    dp[0][0][0] = v[0][0] + v[0][1];
    dp[0][1][1] = v[0][1];
    dp[0][1][2] = v[0][0];
    for (int d = 1; d < N; d++) {
        for (int k = 0; k <= d+1; k++) {
            if(k <= d)
                dp[d][k][0] = tmax(dp[d - 1][k][0], dp[d - 1][k][1], dp[d - 1][k][2]) + v[d][0] + v[d][1];
            
            if (k >= 1) {
                dp[d][k][1] = max(dp[d - 1][k - 1][0], dp[d - 1][k - 1][1]) + v[d][1];
                dp[d][k][2] = max(dp[d - 1][k - 1][0], dp[d - 1][k - 1][2]) + v[d][0];
            }
        }
    }

    cout << tmax(dp[N - 1][K][0], dp[N - 1][K][1], dp[N - 1][K][2]) << endl;

    return 0;
}
