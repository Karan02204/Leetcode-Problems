class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> res;
        intervals.push_back(newInterval);
        sort(intervals.begin(),intervals.end());
        if(intervals.empty()) return res;
        res.push_back(intervals[0]);

        for(int i=0;i<intervals.size();i++){
            vector<int>& last = res.back();
            if(last[1] >= intervals[i][0]){
                last[1] = max(last[1],intervals[i][1]);
            } else{
                res.push_back(intervals[i]);
            }
        }

        return res;
    }
};