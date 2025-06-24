class Solution {
public:
    int mySqrt(int x) {
        long int low = 1;
        long int high = x;
        long int ans = 0;
        while(low<=high){
            long int mid = (low+high)/2;
            if((long long)mid*mid == x){
                return mid;
            }
            if(x>(long long)mid*mid ){
                low = mid+1;
                ans = mid;
            } else {
                high = mid-1;
            }
        }

        return ans;
    }
};