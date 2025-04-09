class Solution {
  public:
    void tarjanDFS(int u, int parent, vector<int> &disc, vector<int> &low,
                   vector<bool> &visited, vector<vector<int>> &adj, 
                   vector<bool> &isArticulation, int &time) {
        visited[u] = true;
        disc[u] = low[u] = time++;
        int children = 0;

        for (int v : adj[u]) {
            if (v == parent) continue;  // Ignore parent edge

            if (!visited[v]) {
                children++;
                tarjanDFS(v, u, disc, low, visited, adj, isArticulation, time);

                // Update low-link value
                low[u] = min(low[u], low[v]);

                // Check articulation point condition
                if (parent != -1 && low[v] >= disc[u])
                    isArticulation[u] = true;
            } else {
                low[u] = min(low[u], disc[v]);
            }
        }

        if (parent == -1 && children > 1)
            isArticulation[u] = true;
    }

    vector<int> articulationPoints(int V, vector<vector<int>>& edges) {
        vector<vector<int>> adj(V);
        for (auto edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        vector<int> disc(V, -1), low(V, -1);
        vector<bool> visited(V, false), isArticulation(V, false);
        int time = 0;

        for (int i = 0; i < V; i++) {
            if (!visited[i])
                tarjanDFS(i, -1, disc, low, visited, adj, isArticulation, time);
        }

        vector<int> result;
        for (int i = 0; i < V; i++) {
            if (isArticulation[i])
                result.push_back(i);
        }

        return result.empty() ? vector<int>{-1} : result;
    }
};
