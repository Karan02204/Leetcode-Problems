class Solution {
public:
    int createPalindrome(int half, bool oddLength) {
        int palindrome = half;
        if (oddLength) half /= 10;
        while (half > 0) {
            palindrome = palindrome * 10 + (half % 10);
            half /= 10;
        }
        return palindrome;
    }

    bool isPrime(int num) {
        if (num < 2) return false;
        for (int i = 2; i * i <= num; ++i) {
            if (num % i == 0) return false;
        }
        return true;
    }

    int primePalindrome(int n) {
        if (n <= 2) return 2;
        if (n <= 3) return 3;
        if (n <= 5) return 5;
        if (n <= 7) return 7;
        if (n <= 11) return 11;

        for (int length = 1; length <= 5; ++length) {
            int start = pow(10, length - 1); // e.g.,1,10,100
            int end = pow(10, length); // e.g.,10,100,1000
            for (int half = start; half < end; ++half) {
                int palindromeOdd = createPalindrome(half, true); // odd length
                if (palindromeOdd >= n && isPrime(palindromeOdd)) {
                    return palindromeOdd;
                }
                int palindromeEven = createPalindrome(half, false);
                if (palindromeEven >= n && isPrime(palindromeEven)) {
                    return palindromeEven;
                }
            }
        }
        return -1;
    }
};