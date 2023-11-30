#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
    string t1="abcde";
    string t2="ace";
    
    int n= t1.size();
    int m= t2.size();
    
    int dp[n+1][m+1]={0};
    
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(t1[i-1] == t2[j-1])
                dp[i][j] = 1+ dp[i-1][j-1];
            else
                dp[i][j] = max(dp[i][j-1],dp[i-1][j]);
        }
    }
    cout<<dp[n][m];
    return 0;
}