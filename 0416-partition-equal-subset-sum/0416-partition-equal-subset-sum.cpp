class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(int i : nums){
            sum+=i;
        }

        if(sum%2!=0){
            return false;
        }

        int n=nums.size();
        int m = sum/2;

        vector<vector<unsigned long long>> dp(n+1,vector<unsigned long long>(m+1,0));
        for(int i=0;i<=n;i++){
            dp[i][0] = 1;
        }

        for(int i=1;i<=n;i++){
            for(int j=0;j<=m;j++){
                if(nums[i-1]>j){
                    dp[i][j] = dp[i-1][j];
                } else if(nums[i-1]<=j){
                    int remaining_balls = j-nums[i-1];
                    dp[i][j] = dp[i-1][j] + dp[i-1][remaining_balls];
                }
            }
        }

        return dp[n][m] > 0;
    }
};