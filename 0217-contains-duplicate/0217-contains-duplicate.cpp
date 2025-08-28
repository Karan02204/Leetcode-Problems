class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        map<int,int> m;

        for(int i=0;i<nums.size();i++){
            m[nums[i]]++;
        }

        for(auto &p : m){
            if(p.second > 1){
                return true;
            }
        }

        return false;
    }
};