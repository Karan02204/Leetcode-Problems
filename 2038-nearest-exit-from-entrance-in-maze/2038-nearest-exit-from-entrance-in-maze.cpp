class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int r = maze.size();
        int c = maze[0].size();

        queue<pair<int,int>> q;
        q.push({entrance[0],entrance[1]});
        maze[entrance[0]][entrance[1]] = '+';

        vector<int> dx = {0,0,-1,1};
        vector<int> dy = {1,-1,0,0};
        int answer = 0;
        while(!q.empty()){
            int size = q.size();

            for(int i=0;i<size;i++){
                pair<int,int> node = q.front();
                q.pop();

                if((node.first!= entrance[0] || node.second!=entrance[1]) && (node.first == r-1 || node.second == c-1 ||node.first == 0 || node.second == 0)){
                    return answer;
                }

                for(int j=0;j<4;j++){
                    int x = node.first + dx[j];
                    int y = node.second + dy[j];

                    if(x>=0 && y>=0 && x<r && y<c && maze[x][y] == '.'){
                        q.push({x,y});
                        maze[x][y] = '+';
                    }
                }

            }
            answer++;
        }

        return -1;
    }
};