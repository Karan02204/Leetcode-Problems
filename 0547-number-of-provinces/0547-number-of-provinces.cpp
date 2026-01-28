class Solution {
public:
    void DFS(int node , vector<vector<int>>& isConnected , vector<bool>& visited){
        visited[node] = true;

        for(int j=0;j<isConnected.size();j++){
            if(isConnected[node][j] == 1 && !visited[j]){
                DFS(j,isConnected,visited);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        vector<bool> visited(isConnected.size(),false);
        int ans = 0;

        for(int i=0;i<isConnected.size();i++){
            if(!visited[i]){
                DFS(i,isConnected,visited);
                ans++;
            }
        }

        return ans;
    }
};