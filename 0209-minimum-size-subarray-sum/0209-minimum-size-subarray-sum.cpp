class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int low = 0 , high = 0;

        int length = INT_MAX;
        int sum = 0;

        while(high < nums.size()){

            sum+=nums[high];
            
            while(sum >= target){
                length = min(length , high - low + 1);
                sum-=nums[low];
                low++;
            }

            high++;

        }

        return length == INT_MAX ? 0 : length;
    }
};