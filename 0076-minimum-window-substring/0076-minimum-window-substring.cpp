class Solution {
public:
    string minWindow(string s, string t) {

        if(t.size() > s.size()) return "";

        unordered_map<char , int> mp;
        for(auto& c : t){
            mp[c]++;
        }

        int i = 0 , j = 0;
        int length = INT_MAX;
        int character_count = 0;
        int startIndex = -1;

        while( j < s.size()){
            if(mp[s[j]] > 0) character_count++;
            mp[s[j]]--;

            while(character_count == t.size()){
                if(j-i+1 < length){
                    length = j-i+1;
                    startIndex = i;
                }

                mp[s[i]]++;
                if(mp[s[i]] > 0) character_count--;
                i++;
            }

            j++;
        }

        return length == INT_MAX ? "" : s.substr(startIndex , length);
    }
};