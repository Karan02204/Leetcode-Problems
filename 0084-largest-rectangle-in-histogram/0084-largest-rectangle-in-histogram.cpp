class Solution {
public:
    vector<int> findNSE(vector<int>& heights){
        int n = heights.size();
        vector<int> ans(n);
        stack<int> st;

        for(int i=n-1;i>=0;i--){
            while(!st.empty() && heights[st.top()] >= heights[i]){
                st.pop();
            }

            ans[i] = st.empty() ? n : st.top();

            st.push(i);
        }

        return ans;
    }

    vector<int> findPSE(vector<int>& heights){
        int n = heights.size();
        vector<int> ans(n);
        stack<int> st;

        for(int i=0;i<n;i++){
            while(!st.empty() && heights[st.top()] >= heights[i]){
                st.pop();
            }

            ans[i] = st.empty() ? -1 : st.top();

            st.push(i);
        }

        return ans;
    }

    int largestRectangleArea(vector<int>& heights) {
        vector<int> nse = findNSE(heights);
        vector<int> pse = findPSE(heights);

        int area = INT_MIN;

        for(int i=0;i<heights.size();i++){
            int sum = (nse[i] - pse[i] - 1) * heights[i];
            area = max(area , sum);
        }

        return area;    
    }
};