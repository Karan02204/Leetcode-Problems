class Solution {
public:
    int helper(int index , vector<int>& nums , vector<int>& dp){

        if(index >= nums.size()) return 0;

        if(dp[index]!=-1) return dp[index];

        int take = nums[index] + helper(index+2 , nums,dp);
        int notTake = helper(index+1 , nums,dp);


        return dp[index] = max(take , notTake);
    }
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size()+2 , 0);

        for(int i = nums.size() - 1;i>=0;i--){

            dp[i] = max( nums[i] + dp[i+2] , dp[i+1]);

        }

        return dp[0];
        // return helper(0 , nums,dp);

    }
};