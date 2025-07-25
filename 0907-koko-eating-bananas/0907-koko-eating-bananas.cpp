class Solution {
public:
    bool Speed(vector<int>&piles , int mid , int h){
        double hours = 0;
        for(int i=0;i<piles.size();i++){
            hours+=ceil((double)piles[i]/mid);
        }

        return hours<=h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 0;
        int high = 1e9;
        int answer;
        while(low<=high){
            int mid = (low+high)/2;
            if(Speed(piles,mid,h)){
                answer = mid;
                high = mid-1;
            } else{
                low = mid+1;
            }
        }

        return answer;
    }
};