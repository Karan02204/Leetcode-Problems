class Solution {
public:
    string convertToTitle(int columnNumber) {

        string result="";
        while(columnNumber>0){
            int rem = columnNumber%26;
            if(rem == 0){
                result.push_back('Z');
                columnNumber = columnNumber/26 - 1;
            } else{
                result.push_back((char)rem+64);
                columnNumber/=26;
            }

        }
        reverse(result.begin(),result.end());
        return result;
    }
};