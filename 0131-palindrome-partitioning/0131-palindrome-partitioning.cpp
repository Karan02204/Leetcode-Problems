class Solution {
public:
    bool palindrome(string s, int low , int high){
        while(low < high){
            if(s[low]!=s[high]){
                return false;
            }
            low++;
            high--;
        }

        return true;
    }

    void func(vector<vector<string>>& result, vector<string>& temp, string s){
        if(s.empty()){
            result.push_back(temp);
            return;
        }

        for(int i=0;i<s.length();i++){
            if(palindrome(s,0,i)){
                string prefix = s.substr(0,i+1);
                temp.push_back(prefix);
                func(result,temp,s.substr(i+1));
                temp.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> result;
        vector<string> temp;
        func(result,temp,s);

        return result;
    }
};