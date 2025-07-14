class Solution {
public:
    int fib(int n) {
        vector<int> store(n+1);
        
        if(n<=1){
            return n;
        }

        store[0] = 0;
        store[1] = 1;


        for(int i=2;i<=n;i++){
            store[i] = store[i-1] + store[i-2];
        }

        return store[n];

    }
};