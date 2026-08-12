class Solution {
public:
    int characterReplacement(string s, int k) {
        
        int i=0 , j = 0;
        int length = INT_MIN;
        int maxFreq = 0;
        unordered_map<char,int> mp;

        while(j < s.size()){

            mp[s[j]]++;
            maxFreq = max(maxFreq , mp[s[j]]);

            while(j-i+1 - maxFreq > k){

                mp[s[i]]--;
                if(mp[s[i]] == 0) mp.erase(s[i]);
                i++;
            }


            length = max(length , j-i+1);
            j++;
        }

        return length == INT_MIN ? 0 : length;
    }
};