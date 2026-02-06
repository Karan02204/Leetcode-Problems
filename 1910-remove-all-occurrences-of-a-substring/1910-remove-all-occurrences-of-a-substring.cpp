class Solution {
public:
    bool firstOccurrence(string s, string part , int& index){
        int n = s.size();
        int m = part.size();

        if (m == 0) return false;

        int i = 0;
        while (i <= n - m) {
            int j = 0;
            
            while (j < m && s[i + j] == part[j]) {
                j++;
            }

            if (j == m){
                index = i;
                return true;
            }
            i++;
        }

        return false;
    }

    string removeOccurrences(string s, string part) {
        int index = -1;

        while(firstOccurrence(s,part,index)){
            int i=0;
            int n = s.size();
            int m = part.size();
            string temp = "";
            while(i<n){
                if(i == index){
                    i+=m;
                } else{
                    temp.push_back(s[i]);
                    i++;
                }
            }
            s = temp;
        }

        return s;
    }
};