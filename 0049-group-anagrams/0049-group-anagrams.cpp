class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> result;
        
        map<string , vector<string>> m;

        for(auto s : strs){
            string temp = s;
            sort(temp.begin(),temp.end());
            m[temp].push_back(s);
        }

        for(const auto &p : m){
            //cout << p.first << " : " ;
            vector<string> temp;
            for(const auto &val : p.second){ // const is used for no copy read-only
                //cout << val << " ";
                temp.push_back(val);
            }

            result.push_back(temp);
        }
        return result;
    }
};