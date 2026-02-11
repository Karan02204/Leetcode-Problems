class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int i =0, j=0;
        int maxi = INT_MIN;
        int length = 0;
        unordered_map<int , int> m;

        while(j < fruits.size()){
            m[fruits[j]]++;
            while(m.size() > 2){
                m[fruits[i]]--;
                if(m[fruits[i]] == 0) m.erase(fruits[i]);
                i++;
            }
            length = j-i+1;
            maxi = max(maxi , length);
            j++;
        }

        return maxi;
    }
};