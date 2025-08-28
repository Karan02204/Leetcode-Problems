class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        vector<int> ans(2*nums.size());

        for(int i=0;i<nums.size();i++){
            ans[i] = nums[i];
        }

        for(int i=nums.size();i<ans.size();i++){
            ans[i] = nums[i-nums.size()];
        }


        return ans;
    }
};