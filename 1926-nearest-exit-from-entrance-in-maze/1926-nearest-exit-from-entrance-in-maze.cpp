class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {

        int r = maze.size();
        int c = maze[0].size();

        if(maze[entrance[0]][entrance[1]] == '+') return -1;

        vector<int> dx = {0 , -1 , 0 , 1}; 
        vector<int> dy = {1 , 0 , -1 , 0};

        queue<pair<int,pair<int,int>>> q;
        q.push({0,{entrance[0] , entrance[1]}});
        maze[entrance[0]][entrance[1]] = '+';
        

        while(!q.empty()){

            auto node = q.front();
            q.pop();

            int steps = node.first;

            if((node.second.first == 0 || node.second.second == 0 || node.second.first == r-1 || node.second.second == c-1) && 
            (node.second.first != entrance[0] || node.second.second != entrance[1])){

                return steps;

            }

            for(int j=0;j<4;j++){

                int x = node.second.first + dx[j];
                int y = node.second.second + dy[j];

                if(x >=0 && y >= 0 && x < r && y < c && maze[x][y] != '+'){

                    q.push({steps+1 , {x,y}});
                    maze[x][y] = '+';

                }

            }

        }

        return -1; 
    }
};