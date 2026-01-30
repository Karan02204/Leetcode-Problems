class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int r = mat.size();
        int c = mat[0].size();

        vector<vector<int>> result(r,vector<int>(c,-1));
        queue<pair<int,int>> q;
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(mat[i][j] == 0){
                    result[i][j] = 0;
                    q.push({i,j});
                }
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
                    int x= node.first + dx[j];
                    int y = node.second + dy[j];

                    if(x>=0 && y>=0 && x<r && y<c && result[x][y] == -1){
                        result[x][y] = result[node.first][node.second] + 1;
                        q.push({x,y});
                    }
                }
            }
        }

        return result;
    }
};