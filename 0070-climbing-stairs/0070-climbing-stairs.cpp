class Solution {
public:
    int climbStairs(int n) {
        if(n<=1){
            return 1;
        }

        vector<int> store(n+1);
        store[0] = 1;
        store[1] = 1;
        for(int i=2;i<=n;i++){
            store[i] = store[i-1] + store[i-2];
        }

        return store[n];
    }
};