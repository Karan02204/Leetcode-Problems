class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> temp(n);
        for(int i=0;i<n;i++){
            temp[(k+i)%n] = nums[i];
        }

        for(int i=0;i<nums.size();i++){
            nums[i] = temp[i];
        }
    }
};