class Solution {
public:
    void DFS(vector<vector<int>>& grid,int i, int j , int r , int c , int& temp){
        if(i==r || j==c || i<0 || j< 0 || grid[i][j] == 0){
            return;
        }

        temp++;
        grid[i][j] = 0;

        DFS(grid,i,j+1,r,c,temp);
        DFS(grid,i-1,j,r,c,temp);
        DFS(grid,i,j-1,r,c,temp);
        DFS(grid,i+1,j,r,c,temp);
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int r = grid.size();
        int c = grid[0].size();
        int ans = 0;
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(grid[i][j] == 1){
                    int temp = 0;
                    DFS(grid,i,j,r,c,temp);
                    ans = max(ans,temp);
                }
            }
        }

        return ans;
    }
};