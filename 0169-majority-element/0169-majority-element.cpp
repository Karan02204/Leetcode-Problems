class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count = 0;
        int maxElement = -1;

        for(int i : nums){
            if(count == 0){
                count++;
                maxElement = i;
            } else if(i == maxElement){
                count++;
            } else{
                count--;
            }
        }

        return maxElement;
    }
};