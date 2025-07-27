class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> answer;
        if(intervals.empty()) return answer;

        sort(intervals.begin(),intervals.end());
        answer.push_back(intervals[0]);
        for(int i = 0 ; i<intervals.size();i++)
        {
            vector<int>& last = answer.back();

            if(last[1] >= intervals[i][0]){
                last[1] = max(last[1],intervals[i][1]);
            } else{
                answer.push_back(intervals[i]);
            }
        }

        return answer;
    }
};