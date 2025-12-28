class Solution {
public:
    bool canCross(vector<int>& stones) {
        unordered_map<int , unordered_set<int>> dp;
        dp[0].insert(0);

        for(int i=0;i<stones.size();i++){
            for(int jump : dp[stones[i]]){
                for(int step=jump-1 ; step<=jump+1 ; step++){
                    if(step > 0){
                        int next = stones[i] + step;
                        if(next == stones.back()) return true;
                        dp[next].insert(step);
                    }
                }
            }
        }

        return false;
    }
};