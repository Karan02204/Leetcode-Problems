class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        sort(meetings.begin(),meetings.end());
        int count = 0;
        vector<vector<int>> res;
        res.push_back(meetings[0]);
        for(int i=1;i<meetings.size();i++){
            vector<int>& last = res.back();
            if(last[1] >= meetings[i][0]){
                last[1] = max(last[1],meetings[i][1]);
            } else{
                res.push_back(meetings[i]);
            }
        }

        for(auto interval : res){
            count  = count + (interval[1] - interval[0]) + 1;
        }

        return days-count;
    }
};