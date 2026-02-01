class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int r = board.size();
        int c = board[0].size();

        queue<pair<int,int>> q;
        for(int i=0;i<r;i++){
            if(board[i][0] == 'O'){
                board[i][0] = '#';
                q.push({i,0});
            }
            if(board[i][c-1] == 'O'){
                board[i][c-1] = '#';
                q.push({i,c-1});
            }
        }

        for(int j=0;j<c;j++){
            if(board[0][j] == 'O'){
                board[0][j] = '#';
                q.push({0,j});
            }
            if(board[r-1][j] == 'O'){
                board[r-1][j] = '#';
                q.push({r-1,j});
            }
        }

        vector<int> dx ={0,-1,0,1};
        vector<int> dy ={1,0,-1,0};

        while(!q.empty()){
            int size = q.size();

            for(int i=0;i<size;i++){
                pair<int,int> node = q.front();
                q.pop();

                for(int j=0;j<4;j++){
                    int x = node.first + dx[j]; 
                    int y = node.second + dy[j];

                    if(x>=0 && y>=0 && x<r && y<c && board[x][y] == 'O'  ){
                        board[x][y] = '#';
                        q.push({x,y});
                    } 
                }
            }
        }

        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(board[i][j] == 'O') board[i][j] = 'X';
                else if(board[i][j] == '#') board[i][j] = 'O';
            }
        }
    }
};