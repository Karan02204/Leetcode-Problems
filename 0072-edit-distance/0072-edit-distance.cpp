class Solution {
public:
    int minDistance(string word1, string word2) {
        //if both the values are same than take diagonally previous element dp[i-1][j-1]. if different then take min(up , left ,and diagonally previous element);

        int n = word1.size();
        int m = word2.size();

        vector<vector<int>> dp(n+1, vector<int>(m+1,0));

        for(int i=0;i<=n;i++){
            dp[i][0] = i;
        }

        for(int j=0;j<=m;j++){
            dp[0][j] = j;
        }

        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(word1[i-1] == word2[j-1]){
                    dp[i][j] = dp[i-1][j-1];
                } else{
                    int temp = min(dp[i-1][j],dp[i][j-1]);
                    dp[i][j] = min(temp,dp[i-1][j-1]) + 1;
                }
            }
        }

        return dp[n][m];
    }
};