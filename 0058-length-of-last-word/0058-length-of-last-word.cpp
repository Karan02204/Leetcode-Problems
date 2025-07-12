class Solution {
public:
    int lengthOfLastWord(string s) {
        vector<string> str;

        string temp = "";
        for(int i=0;i<s.length();i++){
            if(s[i] == ' '){
                temp="";
                continue;
            } else{
                temp += s[i];
            }

            str.push_back(temp);

        }
        
        return str[str.size()-1].length();
    }
};