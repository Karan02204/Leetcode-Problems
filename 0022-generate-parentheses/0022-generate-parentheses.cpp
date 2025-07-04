class Solution {
public:
    void func(vector<string>& result , int n, int open , int close,string temp){
        if(close == n){
            result.push_back(temp);
        }
        if(open < n){
            temp = temp+"(";
            func(result,n,open+1,close,temp);
            temp.pop_back();
        }

        if(open > close){
            temp = temp+")";
            func(result,n,open,close+1,temp);
            temp.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        string temp = "";
        func(result,n,0,0,temp);
        return result;

    }
};