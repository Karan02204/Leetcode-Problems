class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int i = 0 ,j = 0;
        int count = 0;
        int maxi = 0;
        int temp = k;

        while(j<nums.size()){
            if(nums[j] == 1) {
                count++;
                maxi = max(count , maxi);
            }
            else if ( nums[j] == 0 && k>0){
                count++;
                maxi = max(count , maxi);
                k--;
            } else if (nums[j] == 0 && k == 0){
                count = 0;
                i++;
                j=i-1;
                k = temp;
            }
            j++;
        }

        return maxi;
    }
};