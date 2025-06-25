class Solution {
public:
    bool Days(vector<int>& weights, int capacity,int days){
        int count = 1;
        int sum = 0;
        for(int i=0;i<weights.size();i++){
            if(sum+weights[i] <= capacity){
                sum+=weights[i];
            } else{
                sum=weights[i];
                count++;
            }
        }
        return count<=days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int sum=0;
        int max=0;
        int n = weights.size();
        for(int i=0;i<n;i++){
            if(weights[i] > max){
                max = weights[i];
            }
            sum+=weights[i];
        }

        int low = max;
        int high = sum;
        int answer = 0;
        while(low<=high){
            int mid=(low+high)/2;
            if(Days(weights,mid,days)){
                answer = mid;
                high = mid-1;
            } else{
                low = mid+1;
            }
        }


        return answer;    
    }
};