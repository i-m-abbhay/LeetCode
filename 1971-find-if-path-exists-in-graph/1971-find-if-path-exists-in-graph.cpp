class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        if(source == destination) return true;
        vector<vector<int>> graph(n);
        for(auto & e: edges){
            int u=e[0], v =e[1];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        vector<bool> visited(n, false);
        queue<int> q;
        q.push(source);
        visited[source] = true;
        while(!q.empty()){
            int node = q.front(); q.pop();
            if(node==destination) return true;
            for(int neighbor: graph[node]){
                if(!visited[neighbor]){
                    visited[neighbor]=true;
                    q.push(neighbor);
                }
            }
        } 
        return false;
    }
};