class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int r = grid.size();
        int c = grid[0].size();

        queue<pair<int,int>> q;
        int fresh = 0;

        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(grid[i][j] == 1){
                    fresh++;
                } else if(grid[i][j] == 2){
                    q.push({i,j});
                }
            }
        }

        vector<int> dx = {0,-1,0,1};
        vector<int> dy = {1,0,-1,0};

        int min = 0;

        while(!q.empty()){
            int size = q.size();

            for(int i=0;i<size;i++){
                pair<int,int> node = q.front();
                q.pop();

                for(int j=0;j<4;j++){
                    int x = node.first + dx[j];
                    int y = node.second + dy[j];

                    if(x>=0 &&  y>=0 && x<r && y<c && grid[x][y] == 1){
                        grid[x][y] = 2;
                        q.push({x,y});
                        fresh--;
                    }
                }
            }

            if(q.size()>0) min++;
        }

        if(fresh == 0){
            return min;
        }


        return -1;
    }
};