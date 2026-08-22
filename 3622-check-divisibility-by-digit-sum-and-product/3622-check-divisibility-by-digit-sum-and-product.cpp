class Solution {
public:
    int helper_digit_sum(int n){
        int sum = 0;
        while( n > 0){
            int digit = n%10;
            sum+=digit;
            n/=10;
        }

        return sum;
    }

    int helper_product_sum(int n){
        int product = 1;
        while( n > 0){
            int digit = n%10;
            product*=digit;
            n/=10;
        }

        return product;
    }

    bool checkDivisibility(int n) {
        int DigitSum = helper_digit_sum(n);
        int ProductSum = helper_product_sum(n);
        
        int total = DigitSum + ProductSum;
        return (n%total == 0);
    }
};