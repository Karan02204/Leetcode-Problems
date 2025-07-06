class Solution {
public:
    void func(vector<vector<int>>& result,vector<int>& candidates , vector<int>& temp , int target,int index){
        if(target==0){
            result.push_back(temp);
            return;
        }

        for(int i=index;i<candidates.size();i++){
            if(candidates[i]<=target){
                temp.push_back(candidates[i]);
                func(result,candidates,temp,target-candidates[i],i);
                temp.pop_back();
            }
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> temp;
        func(result,candidates,temp,target,0);

        return result;
    }
};