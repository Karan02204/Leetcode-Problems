class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
        for(int i : asteroids){
            while(!st.empty() && st.top()>0 && i < 0){
                int sum = st.top() + i;

                if(sum == 0){
                    i=0;
                    st.pop();
                } else if(sum <0){
                    st.pop();
                } else{
                    i=0;
                }
            }
            if(i!=0){
                st.push(i);
            }
        }

        vector<int> result;
        while(!st.empty()){
            int top = st.top();
            st.pop();
            result.push_back(top);
        }

        reverse(result.begin() , result.end());
        return result;
    }
};