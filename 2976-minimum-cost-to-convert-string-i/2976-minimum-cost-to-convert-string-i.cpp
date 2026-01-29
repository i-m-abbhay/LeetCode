class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        const long long INF = (long long)4e18;
        const int N = 26;
        //min cost to convert u -> v
        vector<vector<long long>> dist(N, vector<long long>(N, INF));
        for(int i=0;i<N;i++) dist[i][i]=0;

        for(int i=0;i<original.size();i++){
            int u = original[i]-'a';
            int v = changed[i]-'a';
            dist[u][v] = min(dist[u][v], (long long)cost[i]);
        }
        
        //floyd warshall computing all pairs shortest paths
        for(int k = 0; k<N; k++){
            for(int i=0;i<N;i++){
                if(dist[i][k]==INF)continue;
                for(int j=0;j<N;j++){
                    if(dist[k][j]==INF) continue;
                    dist[i][j] = min(dist[i][j], dist[i][k]+dist[k][j]);
                }
            }
        }

// Sum cost per character position 
if (source.size() != target.size()) return -1; 
// safety 
long long ans = 0; for (int idx = 0; idx < (int)source.size(); idx++) { int u = source[idx] - 'a'; int v = target[idx] - 'a'; if (dist[u][v] == INF) return -1; // impossible conversion 
ans += dist[u][v]; } return ans;

    }
};