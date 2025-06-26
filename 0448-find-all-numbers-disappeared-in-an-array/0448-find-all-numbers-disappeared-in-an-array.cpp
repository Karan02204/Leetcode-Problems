class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n = nums.size();
        int i=0;
        while(i<n){
            int correctIndex = nums[i]-1;
            if(nums[i]!=nums[correctIndex]){
                int temp = nums[i];
                nums[i] = nums[correctIndex];
                nums[correctIndex] = temp;
            } else{
                i++;
            }
        }

        vector<int> arr;
        for(int i=0;i<n;i++){
            if(nums[i]!=i+1){
                arr.push_back(i+1);
            }
        }

        return arr;
    }
};