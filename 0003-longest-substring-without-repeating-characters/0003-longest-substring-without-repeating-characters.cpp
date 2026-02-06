class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i=0,j=0;
        int length = 0;
        int n = s.size();
        unordered_map<char , int> mp;
        while(j<n){
            mp[s[j]]++;
            while(mp[s[j]] > 1){
                mp[s[i]]--;
                i++;
            }
            length = max(length , j-i+1);
            j++;
        }

        return length;
    }
};