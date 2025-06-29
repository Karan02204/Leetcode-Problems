class Solution {
public:

    bool Speed(vector<int>& piles, int speed ,int h){
        double hours = 0;


        for(int i=0;i<piles.size();i++){
            hours += ceil((double)piles[i]/speed);            
        }

        return hours <= h;
    }

    int minEatingSpeed(vector<int>& piles, int h) {

        int low = 1;
        int max = 0;
        for(int i=0;i<piles.size();i++){
            if(piles[i] > max){
                max = piles[i];
            }
        }
        int high = max;
        int answer = 0;
        while(low<=high){
            int mid = (low+high)/2;
            if(Speed(piles,mid,h)){
                answer = mid;
                high = mid-1;
            } else {
                low = mid+1;
            }
        }

        return answer;
    }
};