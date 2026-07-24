class Solution {
public:
    // int helper(int index , vector<int>& nums , int free , vector<int>& dp){

    //     if(index >= nums.size()) return 0;

    //     if(dp[index][free]!=-1) return dp[index][free];

    //     if(free == 0) return dp[index][free] = helper(index+1 , nums , 1 , dp);

    //     int take = nums[index] + helper(index+1 , nums,0,dp);
    //     int notTake = helper(index+1 , nums,1,dp);


    //     return dp[index][free] = max(take , notTake);
    // }
    int rob(vector<int>& nums) {
        vector<vector<int>> dp(nums.size()+1 , vector<int>(2,0));

        for(int i = nums.size() - 1;i>=0;i--){
            
            dp[i][0] = dp[i+1][1];

            dp[i][1] = max( nums[i] + dp[i+1][0] , dp[i+1][1]);

        }

        return dp[0][1];
        // return helper(0 , nums, 1 , dp);

    }
};