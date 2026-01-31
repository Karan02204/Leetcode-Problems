class Solution {
public:
    void func(vector<int>& nums,vector<vector<int>>& result,vector<int>& temp,int index){
        result.push_back(temp);

        for(int i=index;i<nums.size();i++){
            temp.push_back(nums[i]);
            func(nums,result,temp,i+1);
            temp.pop_back();

        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        int start = 0;
        vector<int> temp;
        func(nums,result,temp,start);
        return result;
    }
};