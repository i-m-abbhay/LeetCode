class Solution {
private:
    bool intersectAtLeastK(const unordered_set<int>& a,
                           const unordered_set<int>& b,
                           int k) {
        int count = 0;
        const auto& small = (a.size() < b.size()) ? a : b;
        const auto& big   = (a.size() < b.size()) ? b : a;

        for (int x : small) {
            if (big.find(x) != big.end()) {
                if (++count >= k) return true;
            }
        }
        return false;
    }

public:
    int numberOfComponents(vector<vector<int>>& properties, int k) {
        int n = properties.size();
        if (n == 0) return 0;
        if (k == 0) return 1; 
 
        vector<unordered_set<int>> sets(n);
        for (int i = 0; i < n; ++i) {
            sets[i] = unordered_set<int>(properties[i].begin(), properties[i].end());
        }

        vector<vector<int>> graph(n);
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (intersectAtLeastK(sets[i], sets[j], k)) {
                    graph[i].push_back(j);
                    graph[j].push_back(i);
                }
            }
        }

        vector<bool> visited(n, false);
        int components = 0;

        for (int start = 0; start < n; ++start) {
            if (visited[start]) continue;
            components++;

            stack<int> st;
            st.push(start);
            visited[start] = true;

            while (!st.empty()) {
                int node = st.top(); st.pop();
                for (int nei : graph[node]) {
                    if (!visited[nei]) {
                        visited[nei] = true;
                        st.push(nei);
                    }
                }
            }
        }

        return components;
    }
};
