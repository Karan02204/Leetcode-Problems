class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int r = grid.size();
        int c = grid[0].size();

        queue<pair<int,int>> q;

        int count = 0;
        for(int i=0;i<r;i++){
            if(grid[i][0] == 1){
                grid[i][0] = 0;
                q.push({i,0});
            }
            if(grid[i][c-1] == 1){
                grid[i][c-1] = 0;
                q.push({i,c-1});
            }
        }

        for(int j=0;j<c;j++){
            if(grid[0][j] == 1){
                grid[0][j] = 0;
                q.push({0,j});
            }
            if(grid[r-1][j] == 1){
                grid[r-1][j] = 0;
                q.push({r-1,j});
            }
        }

        vector<int> dx = {0,-1,0,1};
        vector<int> dy = {1,0,-1,0};

        while(!q.empty()){
            int size = q.size();

            for(int i=0;i<size;i++){
                pair<int,int> node = q.front();
                q.pop();

                for(int j=0;j<4;j++){
                    int x = node.first + dx[j];
                    int y = node.second + dy[j];

                    if(x>=0 && y>=0 && x<r && y<c && grid[x][y] == 1){
                        grid[x][y] = 0;
                        q.push({x,y});
                    }
                }
            }
        }

        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(grid[i][j] == 1) count++;
            }
        }
        return count;
    }
};