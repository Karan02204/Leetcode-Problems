class Solution {
public:
    int jump(vector<int>& nums) {
        int jump=0;
        int reach=0;
        int maxreached = 0;

        for(int i=0;i<nums.size()-1;i++){
            maxreached = max(maxreached,nums[i]+i);
            if(i==reach){
                jump++;
                reach = maxreached;
            }
        }

        return jump;
    }
};