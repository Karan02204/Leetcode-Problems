class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> result(nums1.size());
        vector<int> temp(nums2.size());
        stack<int> st;
        for(int i=nums2.size()-1;i>=0;i--){
            while(!st.empty() && st.top()<=nums2[i]){
                st.pop();
            }

            if(st.empty()) temp[i] = -1;
            else temp[i] = st.top();
            st.push(nums2[i]); 
        }

        int i=0 , j=0;

        while(i<nums1.size()){
            if(nums1[i] == nums2[j]){
                result[i] = temp[j];
                i++;
                j=0;
            }
            else j++;
        }

        return result;
    }
};