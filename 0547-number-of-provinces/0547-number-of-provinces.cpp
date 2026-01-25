class Solution {
    void bfs(int node, vector<vector<int>>& isConnected, int n, vector<int>& vis){
        queue<int> q;
        q.push(node);
        vis[node] = 1;
        while(!q.empty()){
            int vertex = q.front();
            q.pop();
            for(int v = 0; v<n;v++){
                if(isConnected[vertex][v]==1 && !vis[v]){
                    vis[v]=1;
                    q.push(v);
                }
            }
        }

    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int> vis(n, 0);
        int numberOfProvinces = 0;
        for(int i=0;i<n;i++){
            if(vis[i]==0){
                bfs(i, isConnected, n, vis);
                numberOfProvinces++;
            }
        }
        return numberOfProvinces;
    }
};