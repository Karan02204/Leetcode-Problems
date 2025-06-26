class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int correctIndex;
        int i=0;
        while(i<nums.size()){
            if(nums[i]!=i && nums[i] < nums.size()){
                correctIndex = nums[i];
                int temp = nums[i];
                nums[i] = nums[correctIndex];
                nums[correctIndex] = temp;
            } else{
                i++;
            }
        }

        for(int i=0;i<nums.size();i++){
            if(nums[i]!=i){
                return i;
            }
        }

        return nums.size();
    }
};