class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int i =0 , j = 0;
        unordered_map<int,int> mp;

        int length = INT_MIN;

        while( j < nums.size()){

            mp[nums[j]]++;

            while( j-i+1 - mp[1] > k){

                mp[nums[i]]--;
                if(mp[nums[i]] == 0) mp.erase(nums[i]);
                i++;
            }

            length = max(length , j-i+1);

            j++;
        }

        return length == INT_MIN ? 0 : length;
    }
};