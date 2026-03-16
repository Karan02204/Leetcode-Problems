class Solution {
public:
    bool helper(vector<int>& piles , int h , int speed){
        double hours = 0;

        for(int i=0;i<piles.size();i++){
            hours+=ceil((double)piles[i]/speed);
        }
        return hours <= h;
        
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = *max_element(piles.begin() , piles.end());
        int ans;
        while(low <= high){
            int mid = low + (high - low)/2;

            if(helper(piles , h, mid)){
                ans = mid;
                high = mid - 1;
            } else{
                low = mid + 1;
            }
        }

        return ans;
    }
};