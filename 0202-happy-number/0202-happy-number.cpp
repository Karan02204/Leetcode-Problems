class Solution {
public:
    bool helper(int n,set<int>& used){
        if(n == 1) return true;
        if(used.count(n)) return false;

        used.insert(n);
        int sum = 0;
        while(n){
            sum += (n%10)*(n%10);
            n/=10;
        }
        return helper(sum,used);
    }

    bool isHappy(int n) {
        set<int> used;
        return helper(n,used);
    }
};