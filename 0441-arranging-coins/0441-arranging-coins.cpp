class Solution {
public:
    int arrangeCoins(int n) {
        vector<int> arr;

        for(int i=1;i<=n;i++){
            n = n - i;

            if(n < 0){
                arr.push_back(abs(n));
                break;
            } else arr.push_back(i);
        }

        int low = 0;
        int high = arr.size() - 1;

        while(low <= high){
            int mid = (low+high)/2;

            if(arr[mid]!=mid+1){
                high = mid - 1;
            } else{
                low = mid + 1;
            }
        }

        return low;
    }
};