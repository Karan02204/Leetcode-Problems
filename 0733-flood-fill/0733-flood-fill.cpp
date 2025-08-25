class Solution {
public:
    void DFS(vector<vector<int>>& image , int i , int j , int r , int c , int oldColor , int newColor){
        if( i == r || j == c || i<0 || j < 0 || image[i][j]!=oldColor || image[i][j] == newColor){
            return;
        }

        image[i][j] = newColor;

        DFS(image , i , j+1 , r , c , oldColor , newColor);
        DFS(image , i-1 , j , r , c , oldColor , newColor);
        DFS(image , i , j-1 , r , c , oldColor , newColor);
        DFS(image , i+1 , j , r , c , oldColor , newColor);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int r = image.size();
        int c = image[0].size();

        int oldColor = image[sr][sc];

        DFS(image , sr , sc , r , c , oldColor , color);


        return image;
    }
};