class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
       vector<int> result;
       int leftsum = 0;
       int rightsum = 0;
       int totalsum = 0;

       for(int i : nums) totalsum += i;

       for(int i=0;i<nums.size();i++){
        rightsum = totalsum - leftsum - nums[i];
        result.push_back(abs(leftsum - rightsum));
        leftsum += nums[i];
       }

       return result;

    }
};