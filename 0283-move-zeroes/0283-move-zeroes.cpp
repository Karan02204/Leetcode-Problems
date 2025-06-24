class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        int x=0;
        for(int i=0;i<n;i++){
            if(nums[i]!=0){
                nums[x++] = nums[i];
            }
        }

        while(x<nums.size()){
            nums[x++] = 0;
        }
    }
};