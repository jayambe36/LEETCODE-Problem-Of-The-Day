static auto init = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector<vector<int>> adj(n);
        for (auto &p : prerequisites) adj[p[0]].push_back(p[1]);
        vector<bitset<101>> memo(n);
        vector<bool> visited(n, false);

        function<void(int)> dfs = [&](int s) {
            visited[s] = true;
            for (auto t : adj[s]) {
                if (!visited[t]) dfs(t);
                memo[s] |= memo[t];
                memo[s].set(t);
            }
        };

        for (int i = 0; i < n; ++i) {
            if (!visited[i]) dfs(i);
        }

        vector<bool> ans;
        ans.reserve(queries.size());
        for (auto &q : queries) {
            ans.push_back(memo[q[0]][q[1]]);
        }
        return ans;
    }
};