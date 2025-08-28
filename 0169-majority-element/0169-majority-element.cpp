class Solution {
public:
    int majorityElement(vector<int>& nums) {
        map<int , int> m;

        for(auto val : nums){ //storing the frequency of elements
            m[val]++;
        }

        int max=0;
        int ans;
        for(const auto &p : m){ //extract the element with the max frequency
            if(p.second > max){
                max = p.second;
                ans = p.first;
            }
        }

        return ans;
    }
};