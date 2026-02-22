class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> st;
        string result = "";
        if(k == 0) return result;
        int n = num.size();

        for(char c : num){
            while(!st.empty() && st.top() > c && k>0){
                st.pop();
                k--;
            }
            st.push(c);
        }
        
        while(!st.empty() && k>0){
            st.pop();
            k--;
        }

        if(st.empty()) return "0";
        while(!st.empty()){
            result.push_back(st.top());
            st.pop();
        }

        while(result.size() > 1 && result.back() == '0'){
            result.pop_back();
        }
        if(result.empty()) return "0";
        reverse(result.begin() , result.end());
        return result;
    }
};