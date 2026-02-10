class Solution {
public:
    int numberOfSubstrings(string s) {
        int i =0 , j = 0;
        int n = s.size();
        int count = 0;
        map<char,int> m;
        while(j < n){
            m[s[j]]++;
            while(m.size() == 3){
                count+=(n-j);
                m[s[i]]--;
                if(m[s[i]] == 0) m.erase(s[i]);
                i++;
            }
            j++;
        }

        return count;
    }
};