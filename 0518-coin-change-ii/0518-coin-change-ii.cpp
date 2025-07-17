class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        int m = amount;

        vector<vector<unsigned long long>> dp(n+1,vector<unsigned long long>(m+1,0));

        for(int i=0;i<=n;i++){
            dp[i][0] = 1;
        }

        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(coins[i-1]>j){
                    dp[i][j] = dp[i-1][j];
                } else if (coins[i-1] <= j){
                    int remaining_balls = j-coins[i-1];
                    dp[i][j] = dp[i-1][j] + dp[i][remaining_balls];
                }
            }
        }

        return dp[n][m];
    }
};