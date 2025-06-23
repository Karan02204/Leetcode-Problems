class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int lsum = 0;
        int rsum=0;
        int sum=0;
        for(int i : nums){
            sum+=i;
        }

        for(int i=0;i<nums.size();i++){
            if(i>0){
                lsum = lsum + nums[i-1];
            }
            rsum = sum - nums[i];
            sum = rsum;
            if(lsum == rsum){
                return i;
            }
        }

        return -1;
    }
};