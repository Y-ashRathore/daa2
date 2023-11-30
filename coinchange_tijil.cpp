#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n = 3;
    int coins[n] = {25,10,5};
    int amt = 30;
    int dp[n+1][amt+1];
    for(int i=0;i<n;i++){
        dp[i][0] = 0;
    }
    for(int j=0;j<=amt;j++){
        dp[0][j] = INT_MAX-1;
    }
    
    
    for(int i=1;i<=n;i++){
        for(int j=1;j<=amt;j++){
            if(coins[i-1] > j)
                dp[i][j] = dp[i-1][j];
			else 
			    dp[i][j] = min(dp[i-1][j], 1 + dp[i][j-coins[i-1]]);
        }
    }
    cout << dp[n][amt];
    return 0;
}