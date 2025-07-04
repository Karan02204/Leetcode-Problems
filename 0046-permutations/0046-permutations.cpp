class Solution {
public:
    void func(vector<int>& nums, vector<vector<int>>& result , vector<int>& temp , int index){
        if(temp.size() == nums.size()){
            result.push_back(temp);
            return;
        }

        for(int i=0;i<nums.size();i++){
            if(find(temp.begin(),temp.end(),nums[i]) != temp.end()) continue;
            temp.push_back(nums[i]);
            func(nums,result,temp,i+1);
            temp.pop_back();
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> result;
        vector<int> temp;
        func(nums,result,temp,0);
        return result;
    }
};