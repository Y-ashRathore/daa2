#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n = 4;
    int val[n] = {15, 10, 9, 5};
    int w[n] = {1, 5, 3, 4};
    int c = 8;
    int dp[n + 1][c + 1] = {0};

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= c; j++) {
            if (w[i - 1] <= j)
                dp[i][j] = max(dp[i - 1][j], val[i - 1] + dp[i - 1][j - w[i - 1]]);
            else
                dp[i][j] = dp[i - 1][j];
        }
    }
    cout << dp[n][c];
    return 0;
}