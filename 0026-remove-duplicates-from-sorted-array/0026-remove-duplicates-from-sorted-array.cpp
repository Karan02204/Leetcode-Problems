class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i=1;
        int n = nums.size();
        int prev = nums[0];
        while(i<n){
            if(nums[i]!=prev){
                prev = nums[i];
                i++;
            } else{
                int curr = nums[i];
                for(int j=i;j<n-1;j++){
                    nums[j] = nums[j+1];
                }
                n--;
            }
        }

        return n;
    }
};