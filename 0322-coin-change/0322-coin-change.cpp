class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        int m = amount;

        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        for(int i=1;i<=m;i++){
            dp[0][i] = INT_MAX - 1 ;
        }

        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(coins[i-1] > j){
                    dp[i][j] = dp[i-1][j];
                } else if (coins[i-1] <= j){
                    int remaining_balls = j-coins[i-1];
                    dp[i][j] = min(dp[i-1][j],1+dp[i][remaining_balls]);
                }
            }
        }

        return dp[n][m] == INT_MAX-1 ? -1 : dp[n][m];
    }
};