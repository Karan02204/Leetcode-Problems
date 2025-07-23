class Solution {
public:
    int trap(vector<int>& height) {
        vector<int> left;
        vector<int> right(height.size());
        left.push_back(height[0]);
        for(int i=1;i<height.size();i++){
            left.push_back(max(left[i-1],height[i]));
        }
        right[height.size()-1] = height[height.size()-1];

        for(int i=height.size()-2;i>=0;i--){
            right[i] = max(right[i+1] , height[i]);
        }
        

        int water = 0;
        for(int i=0;i<left.size();i++){
            water = water + min(left[i],right[i]) - height[i];
        }

        return water;
    }
};