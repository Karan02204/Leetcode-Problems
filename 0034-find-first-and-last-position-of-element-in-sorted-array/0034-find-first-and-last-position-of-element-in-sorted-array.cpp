class Solution {
public:
    int firstOccurrence(vector<int>& nums, int target){
        int low = 0;
        int high = nums.size() -1;
        int answer = -1;
        while(low <= high){
            int mid = (low+high)/2;
            if(nums[mid] == target){
                answer = mid;
                high = mid-1;
            }else if(target > nums[mid]){
                low = mid+1;
            } else{
                high = mid -1;
            }
        }

        return answer;

    }

    int lastOccurrence(vector<int>& nums, int target){
        int low = 0;
        int high = nums.size() -1;
        int answer = -1;
        while(low <= high){
            int mid = (low+high)/2;
            if(nums[mid] == target){
                answer = mid;
                low = mid+1;
            } else if(target > nums[mid]){
                low = mid+1;
            } else{
                high = mid -1;
            }
        }

        return answer;

    }

    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans(2,0);
        ans[0] = firstOccurrence(nums,target);
        ans[1] = lastOccurrence(nums,target);

        return ans;
    }
};