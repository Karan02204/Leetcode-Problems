class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        while(nums.size() > 1){
            nums[0] = nums[0] ^ nums[1];
            nums.erase(nums.begin()+1);
        }

        return nums[0];
    }
};