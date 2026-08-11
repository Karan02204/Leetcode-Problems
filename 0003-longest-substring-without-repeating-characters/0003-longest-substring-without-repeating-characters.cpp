class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i = 0 , j = 0;
        int length = INT_MIN;

        unordered_map<char,int> mp;

        while(j < s.size()){
            mp[s[j]]++;

            while(mp[s[j]] > 1){
                mp[s[i]]--;
                i++;
            }

            length = max(length , j-i+1);
            j++;
        }

        return length == INT_MIN ? 0  : length;
    }
};