class Solution {
public:
    int hammingWeight(int n) {
        vector<int> arr;
        while(n>0){
            int remainder = n%2;
            n/=2;
            arr.push_back(remainder);
        }

        int count=0;
        for(int i : arr){
            if(i==1){
                count++;
            }
        }

        return count;
    }
};