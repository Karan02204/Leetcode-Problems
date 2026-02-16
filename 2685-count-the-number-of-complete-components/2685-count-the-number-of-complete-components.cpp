class Solution {
public:
    void dfs(int node , vector<vector<int>>& adj , vector<bool>& visited , int& nodes , int& edgesum){
        visited[node] = true;
        nodes++;
        edgesum += adj[node].size();

        for(auto& neigh : adj[node]){
            if(!visited[neigh]){
                dfs(neigh , adj , visited, nodes , edgesum);
            }
        }
    }
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);

        for(auto& e : edges){
            int u = e[0];
            int v = e[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<bool> visited(n,false);
        int count =0;
        for(int i=0;i<n;i++){
            if(!visited[i]){
                int nodes = 0;
                int edgesum = 0;
                dfs(i , adj , visited, nodes , edgesum);

                int totalEdges = (edgesum)/2;
                if(totalEdges == (nodes*(nodes-1)/2)) count++;
            }
        }

        return count;
    }
};