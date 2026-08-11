class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        
        int length  = INT_MIN;
        int i = 0 , j = 0;
        unordered_map<int , int> mp;

        while(j < fruits.size()){
            mp[fruits[j]]++;

            while(mp.size() > 2){
                mp[fruits[i]]--;
                if(mp[fruits[i]] == 0) mp.erase(fruits[i]);
                i++;
            }

            length = max(length , j-i+1);
            j++;
        }

        return length;
    }
};