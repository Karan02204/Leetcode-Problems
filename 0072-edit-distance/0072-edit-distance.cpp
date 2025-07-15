class Solution {
public:
    int minDistance(string word1, string word2) {
       //if both the values are same than take diagonally previous element dp[i-1][j-1]. if different then take min(up , left ,and diagonally previous element);

       int n=word1.size();
       int m = word2.size();

       vector<vector<int>> dp(n+1,vector<int>(m+1,0));

       for(int i=0;i<=n;i++){
            dp[i][0] = i;
       }

       for(int i=0;i<=m;i++){
            dp[0][i] = i;
       }

       for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(word1[i-1] == word2[j-1]){
                dp[i][j] = dp[i-1][j-1];
            } else {
                int temp = min(dp[i-1][j],dp[i][j-1]);
                dp[i][j] = min(temp,dp[i-1][j-1])+1;
            }
        }
       }
        for(int i=0;i<=n;i++){
            for(int j=0;j<=m;j++){
                cout << dp[i][j] << " ";
            }
            cout << endl;
        }

       return dp[n][m]; 
    }
};