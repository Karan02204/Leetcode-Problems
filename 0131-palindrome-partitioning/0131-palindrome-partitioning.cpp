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

    void func(vector<vector<string>>& result, vector<string>& temp, string s ,int index){
        if(index == s.length()){
            result.push_back(temp);
            return;
        }

        for(int i=index;i<s.length();i++){
            if(palindrome(s,index,i)){
                temp.push_back(s.substr(index, i - index + 1));
                func(result,temp,s,i+1);
                temp.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> result;
        vector<string> temp;
        func(result,temp,s,0);

        return result;
    }
};