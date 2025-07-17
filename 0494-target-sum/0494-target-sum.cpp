class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int sum = 0;
        for(int i : nums){
            sum+=i;
        }

        int m = (sum+target)/2;

        if(target>sum || target<-sum || (target+sum)%2!=0){
            return 0;
        }

        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        for(int i=0;i<=n;i++){
            dp[i][0] =  1;
        }
        for(int i=1;i<=n;i++){
            for(int j=0;j<=m;j++){
                dp[i][j] = dp[i-1][j];
                if(nums[i-1]<=j){
                    int remaining_balls  = j-nums[i-1];
                    dp[i][j] = dp[i-1][j] + dp[i-1][remaining_balls];
                }
            }
        }

        return dp[n][m];
    }
};