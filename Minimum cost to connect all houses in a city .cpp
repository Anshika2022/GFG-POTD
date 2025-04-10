class Solution {
  public:
    int minCost(vector<vector<int>>& houses) {
        // code here
        int n = houses.size();
        if (n == 0) return 0;

        vector<bool> visited(n, false);
        vector<int> minDist(n, INT_MAX);
        minDist[0] = 0;

        int totalCost = 0;

        for (int i = 0; i < n; ++i) {
            int u = -1;
            for (int j = 0; j < n; ++j) {
                if (!visited[j] && (u == -1 || minDist[j] < minDist[u])) {
                    u = j;
                }
            }

            visited[u] = true;
            totalCost += minDist[u];

            for (int v = 0; v < n; ++v) {
                if (!visited[v]) {
                    int cost = abs(houses[u][0] - houses[v][0]) + abs(houses[u][1] - houses[v][1]);
                    if (cost < minDist[v]) {
                        minDist[v] = cost;
                    }
                }
            }
        }

        return totalCost;
    }
};
