class Solution {
private:
    int intersect(vector<int>&a,vector<int>&b){
        unordered_set<int> st_from_a(a.begin(),a.end());
        int count = 0;
        for(auto el: b){
            if(st_from_a.find(el)!=st_from_a.end()){
                count++;
                st_from_a.erase(el);
            }
        }
        return count;
    }
public:
    int numberOfComponents(vector<vector<int>>& properties, int k) {
        int n = properties.size();  
        vector<vector<int>> graph(n);
        for(int i = 0; i<n;i++){
            for(int j=i+1;j<n;j++){
                if(intersect(properties[i], properties[j])>=k){
                    graph[i].push_back(j);
                    graph[j].push_back(i);              
                }
            }
        }

        vector<bool> visited(n, false);
        int components = 0;
        for(int start = 0; start<n; start++){
            if(visited[start]) continue;
            components++;
            stack<int> st;
            st.push(start);
            visited[start] = true;

            while(!st.empty()){
                int node = st.top(); st.pop();
                for(int nei: graph[node]){
                    if(!visited[nei]){
                        visited[nei]= true;
                        st.push(nei);
                    }
                }
            }
        }
        return components;        
    }
};