class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int correctIndex;
        int i=0;
        vector<int> answer;
        while(i<nums.size()){
            correctIndex = nums[i] - 1;
            if(nums[i]!=nums[correctIndex]){
                int temp = nums[i];
                nums[i] = nums[correctIndex];
                nums[correctIndex] = temp;
            } else{
                i++;
            }
        }

        for(int i=0;i<nums.size();i++){
            if(nums[i]!=i+1){
                answer.push_back(nums[i]);
                answer.push_back(i+1);
            }
        }

        return answer;
    }
};