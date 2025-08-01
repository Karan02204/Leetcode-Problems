class Solution {
public:
    int findMin(vector<int>& nums) {
        int low=0;
        int high = nums.size()-1;

        while(low<high){
            int mid = (low+high)/2;
            if(nums[low] == nums[mid] && nums[high] == nums[mid]){
                low++;
                high--;
                continue;
            }
            if(nums[mid] > nums[high]){
                low = mid+1;
            } else{
                high = mid;
            }

        }
        return nums[low];
    }
};