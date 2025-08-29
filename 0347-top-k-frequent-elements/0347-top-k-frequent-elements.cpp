class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        vector<int> result;

        map<int , int> m;

        for(auto val : nums){
            m[val]++;
        }

        // for(const auto &p : m){
        //     cout << p.first << " " << p.second << endl;
        // }

        for(int i=0;i<k;i++){
            int max = 0;
            int ans=0;
            for(auto &c : m){
                if(c.second > max){
                    max = c.second;
                    ans = c.first;
                }
            }

            result.push_back(ans);
            m[ans]=0;
        }

        return result;
    }
};
