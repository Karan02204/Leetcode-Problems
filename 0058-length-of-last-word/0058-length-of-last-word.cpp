class Solution {
public:
    int lengthOfLastWord(string s) {
        int length = 0;

        int j=s.size()-1;
        while(s[j] == ' '){
            j--;
        }
        while(j>=0){
            if(s[j] == ' '){
                break;
            }
            length++;
            j--;
        }

        return length;
    }
};