class Solution {
public:
    int helper_first(vector<int>& nums , int target){
        int ans = -1;

        int low = 0;
        int high = nums.size()-1;

        while(low<=high){
            int mid = (low+high)/2;

            if(nums[mid] == target){
                ans = mid;
                high = mid - 1;
            } else if(nums[mid] < target){
                low = mid + 1;
            } else{
                high = mid -1;
            }
        }

        return ans;
    }

    int helper_last(vector<int>& nums , int target){
        int ans = -1;

        int low = 0;
        int high = nums.size()-1;

        while(low<=high){
            int mid = (low+high)/2;

            if(nums[mid] == target){
                ans = mid;
                low = mid + 1;
            } else if(nums[mid] < target){
                low = mid + 1;
            } else{
                high = mid - 1;
            }
        }

        return ans;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        int first = helper_first(nums,target);
        int last = helper_last(nums , target);

        vector<int> ans;
        ans.insert(ans.end() , {first , last});

        return ans;
    }
};