class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        int i = 0 , k=0;
        int j = n;
        vector<int> ans(nums.size());
        while(k<nums.size()){
            if(k%2==0) {
                ans[k] = nums[i];
                i++;
            } else{
                ans[k] = nums[j];
                j++;
            }
            k++;
        }

        return ans;
    }
};