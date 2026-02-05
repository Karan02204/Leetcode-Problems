class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size()!=t.size()) return false;
        vector<int> f1(26,0) , f2(26,0);

        for(int i=0;i<s.size();i++){
            f1[s[i] - 97]++;
        }
        for(int i=0;i<t.size();i++){
            f2[t[i] - 97]++;
        }

        cout << 'g' - 97;
        cout << 'i' - 97;

        cout << 'e' - 97;
        cout << 'k' - 97;

        for(int i=0;i<f1.size();i++){
            if(f1[i]!=f2[i]) return false;
        }


        return true;
    }
};