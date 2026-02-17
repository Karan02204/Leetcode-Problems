class Solution {
public:
    void dfs(int node , vector<vector<int>>& isConnected , vector<bool>& visited){
        visited[node] = true;

        for(int j=0;j<isConnected.size();j++){
            if(isConnected[node][j] == 1 && !visited[j]){
                dfs(j , isConnected , visited);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        vector<bool> visited(isConnected.size() , false);
        int count  = 0;
        for(int i=0;i<isConnected.size();i++){
            if(!visited[i]){
                dfs(i,isConnected,visited);
                count++;
            }
        }

        return count;
    }
};