class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);

        for(int i=0;i<prerequisites.size();i++){
            int u = prerequisites[i][0];
            int v = prerequisites[i][1];

            adj[u].push_back(v);
        }

        vector<int> Indegree(numCourses);

        for(int i=0;i<adj.size();i++){
            for( int j=0;j<adj[i].size();j++){
                Indegree[adj[i][j]]++;
            }
        }

        queue<int> q;
        vector<int> ans;

        for(int i=0;i<Indegree.size();i++){
            if(Indegree[i] == 0){
                q.push(i);
            }
        }

        while(!q.empty()){
            int node = q.front();
            q.pop();

            ans.push_back(node);

            for(int i=0;i<adj[node].size();i++){
                Indegree[adj[node][i]]--;

                if(Indegree[adj[node][i]] == 0){
                    q.push(adj[node][i]);
                }
            }
        }
        reverse(ans.begin(),ans.end());
        if(ans.size()!=numCourses){
            return {};
        } else return ans;
    }
};