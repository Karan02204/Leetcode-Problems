class Solution {
public:
    void solver(vector<int>& nums , vector<int>& temp , vector<vector<int>>& result , int index){
        result.push_back(temp);

        for(int i=index;i<nums.size();i++){
            temp.push_back(nums[i]);
            solver(nums,temp,result,i+1);
            temp.pop_back();
        }

    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> temp;
        solver(nums,temp,result,0);
        return result;
    }
};