class Solution {
public:
    int helper(vector<int>& nums , int goal){
        if (goal < 0) return 0;

        int i = 0, sum = 0, count = 0;

        for (int j = 0; j < nums.size(); j++) {
            sum += nums[j];

            while (sum > goal) {
                sum -= nums[i];
                i++;
            }

            count += (j - i + 1);
        }

        return count;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return helper(nums,goal) - helper(nums,goal - 1);
    }
};