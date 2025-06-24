class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int length=0;
        int maxCount = 0;
        for(int i=0;i<nums.size();i++){
            if(nums[i] == 1){
                length++;
                maxCount = max(length,maxCount);
            } else if(nums[i] == 0){
                length = 0;
            }
        }

        return maxCount;
    }
};