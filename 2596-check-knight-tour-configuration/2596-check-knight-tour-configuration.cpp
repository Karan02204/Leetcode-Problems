class Solution {
public:
    bool checkValidGrid(vector<vector<int>>& grid) {
        
        int n = grid.size();


        int i=0 , j = 0;

        if(grid[0][0]!=0) return false;
        vector<int> dx = {-2 , -2 , -1 , 1 , -1 , 1 , 2 , 2};
        vector<int> dy = {-1 , 1 , 2 , 2 , -2 , -2 , 1 , -1};

        queue<pair<int,pair<int,int>>> q;
        q.push({0 , {0 , 0}});

        while(!q.empty()){

            auto node = q.front();
            q.pop();

            int steps = node.first;

            if(steps == n*n-1) return true;

            for(int i=0;i<8;i++){
                
                int x = node.second.first + dx[i];
                int y = node.second.second + dy[i];

                if(x >=0 && y>=0 && x < n && y < n && grid[x][y] == steps+1){
                    q.push({steps+1 , {x,y}});
                    break;
                }
            }

        }

        return false;
    }
};