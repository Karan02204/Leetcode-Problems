class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n=nums.size();
        int i=0;

        while(i<n){
            if(nums[i] > 0 && nums[i] <= n && nums[i] != nums[nums[i]-1]){
                int correctIndex = nums[i]-1;
                int temp = nums[i];
                nums[i] = nums[correctIndex];
                nums[correctIndex] = temp;
            } else{
                i++;
            }
        }

        for(int i=0;i<n;i++){
            if(nums[i]!=i+1){
                return i+1;
            }
        }

        return n+1;
    }
};