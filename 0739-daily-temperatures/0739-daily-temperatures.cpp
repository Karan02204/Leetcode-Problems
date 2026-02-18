class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> answer;
        stack<int> st;

        vector<int> result;
        result.push_back(0);
        st.push(temperatures.size()-1);
        
        
        for(int i=temperatures.size()-2;i>=0;i--){
            while(!st.empty() && temperatures[st.top()] <= temperatures[i]) st.pop();
            if(st.empty()) result.push_back(0);
            else result.push_back(st.top() - i);
            st.push(i);
        }
        
        reverse(result.begin() , result.end());
        return result;
    }
};