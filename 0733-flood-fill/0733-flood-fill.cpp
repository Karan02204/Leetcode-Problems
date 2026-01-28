class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int r= image.size();
        int c = image[0].size();

        queue<pair<int,int>> q;
        q.push({sr,sc});
        int pixel = image[sr][sc];
        image[sr][sc] = color;

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

                    if(x>=0 && y>=0 && x<r && y<c && image[x][y] == pixel  && image[x][y]!=color){
                        q.push({x,y});
                        image[x][y] = color;
                    }
                }
            }
        }

        return image;
    }
};