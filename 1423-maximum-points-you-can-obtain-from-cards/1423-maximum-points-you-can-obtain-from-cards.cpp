class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int i = 0 , j = 0;
        int window = cardPoints.size() - k;
        int sum = 0 , minisum = INT_MAX;
        while(j<cardPoints.size()){
            sum += cardPoints[j];
            if(j-i+1 > window){
                sum -= cardPoints[i];
                i++;
            }
            if(j-i+1 == window){
                minisum = min(minisum , sum);
            }
            j++;
        }
        cout << minisum << " ";
        sum = 0;
        for(int i : cardPoints){
            sum += i;
        }

        return sum - minisum;
    }
};