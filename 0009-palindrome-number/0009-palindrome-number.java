class Solution {
    public boolean isPalindrome(int x) {
        int temp = x;
        int remainder;
        int reversednumber = 0;
        while(temp>0){
            remainder = temp%10;
            reversednumber = (reversednumber * 10) + remainder;
            temp/=10;
        }

        if(reversednumber == x){
            return true;
        } else{
            return false;
        }
    }
}