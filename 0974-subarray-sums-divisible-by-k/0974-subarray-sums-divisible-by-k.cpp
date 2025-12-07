class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int, int> remainder_counts;
        remainder_counts[0] = 1;
        int count = 0;
        int current_sum = 0;
        for(int num : nums){
            current_sum += num;

            int remainder = current_sum % k;
            if(remainder < 0){
                remainder += k;
            }

            if(remainder_counts.count(remainder)){
                count += remainder_counts[remainder];
            }

            remainder_counts[remainder]++;

        }

        return count;
    }
};