class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int i=0;
        int n= nums.size();
        while(i<n){
            int correctIndex = nums[i] - 1;
            if(nums[i]!=nums[correctIndex]){
                int temp = nums[i];
                nums[i] = nums[correctIndex];
                nums[correctIndex] = temp;
            } else{
                i++;
            }
        }

        for(int i=0;i<n;i++){
            if(nums[i]!=i+1){
                return nums[i];
            }
        }

        return 0;
    }
};