class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i=0,j=0;
        int length = 0;
        int n = s.size();
        unordered_map<char,int> m;
        while(j<n){
            m[s[j]]++;
            while(m[s[j]] > 1){
                m[s[i]]--;
                i++;
            }
            length = max(length , j-i+1);
            j++;
        }

        return length;
    }
};