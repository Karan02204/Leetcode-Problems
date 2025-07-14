class Solution {
public:
    int tribonacci(int n) {
        if(n<=1){
            return n;
        }

        vector<int> store(n+1);
        store[0] = 0;
        store[1] = 1;
        store[2] = 1;

        for(int i=3;i<=n;i++){
            store[i] = store[i-1] + store[i-2] + store[i-3];
        }

        return store[n];
    }
};