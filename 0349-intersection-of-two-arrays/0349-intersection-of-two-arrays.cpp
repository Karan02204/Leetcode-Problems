class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> st1(nums1.begin(),nums1.end());
        
        unordered_set<int> st2(nums2.begin(),nums2.end());

        unordered_map<int,int> map;
        for(auto i : st1){
            map[i]++;
        }
        for(auto i : st2){
            map[i]++;
        }
        
        vector<int> result;
        for(auto e : map){
            if(e.second > 1) result.push_back(e.first);
        }

        return result;
    }
};