class Solution {
public:
    int longestValidParentheses(string s) {
        int close = 0;
        int open = 0;
        int answer = 0;

        for(char c : s){
            if(c == '(') open++;
            else close++;

            if(open == close) answer = max(answer,2*open);
            else if (close > open){
                close = 0;
                open = 0;
            }
        }

        close = 0, open = 0;

        for(int i=s.size()-1;i>=0;i--){
            if(s[i] == '(') open++;
            else close++;

            if(open == close) answer = max(answer,2*open);
            else if(open>close){
                close = 0;
                open = 0;
            }
        }

        return answer;
    }
};